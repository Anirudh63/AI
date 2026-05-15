#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<vector<int>> state;
    int x, y; // position of blank tile
    int g, h;

    bool operator>(const Node& other) const {
        return (g + h) > (other.g + other.h);
    }
};

vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

map<int, pair<int,int>> goalPos;

// Convert matrix to string for visited set
string serialize(vector<vector<int>>& mat) {
    string s = "";
    for (auto &row : mat)
        for (int val : row)
            s += to_string(val);
    return s;
}

// Manhattan Distance Heuristic
int heuristic(vector<vector<int>>& state) {
    int dist = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            int val = state[i][j];

            if (val != 0) {
                int gx = goalPos[val].first;
                int gy = goalPos[val].second;

                dist += abs(i - gx) + abs(j - gy);
            }
        }
    }

    return dist;
}

// Print puzzle state
void printState(vector<vector<int>>& state) {
    for (auto &row : state) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
    cout << "---------" << endl;
}

void aStar(vector<vector<int>> start) {

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    int sx, sy;

    // Find blank tile
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (start[i][j] == 0) {
                sx = i;
                sy = j;
            }
        }
    }

    Node initial = {start, sx, sy, 0, heuristic(start)};

    pq.push(initial);

    unordered_set<string> visited;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {

        Node curr = pq.top();
        pq.pop();

        string key = serialize(curr.state);

        if (visited.count(key))
            continue;

        visited.insert(key);

        // Goal check
        if (curr.state == goal) {
            cout << "Goal State Reached!\n\n";
            printState(curr.state);

            cout << "Moves Required = " << curr.g << endl;
            return;
        }

        // Generate next states
        for (int k = 0; k < 4; k++) {

            int nx = curr.x + dx[k];
            int ny = curr.y + dy[k];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {

                vector<vector<int>> newState = curr.state;

                swap(newState[curr.x][curr.y], newState[nx][ny]);

                string newKey = serialize(newState);

                if (!visited.count(newKey)) {

                    Node next;

                    next.state = newState;
                    next.x = nx;
                    next.y = ny;
                    next.g = curr.g + 1;
                    next.h = heuristic(newState);

                    pq.push(next);
                }
            }
        }
    }

    cout << "No Solution Found\n";
}

int main() {

    // Goal positions for heuristic
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            goalPos[goal[i][j]] = {i, j};
        }
    }

    vector<vector<int>> start = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    cout << "Initial State:\n";
    printState(start);

    aStar(start);

    return 0;
}