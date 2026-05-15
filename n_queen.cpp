#include <bits/stdc++.h>
using namespace std;

void solve(int col,
           vector<string>& board,
           vector<vector<string>>& ans,
           int n,
           map<int,int>& rowCheck,
           map<int,int>& lowerDiagonal,
           map<int,int>& upperDiagonal) {

    // Base Case
    if (col == n) {
        ans.push_back(board);
        return;
    }

    // Try placing queen in every row
    for (int row = 0; row < n; row++) {

        // Branch and Bound check
        if (rowCheck[row] == 0 &&
            lowerDiagonal[row + col] == 0 &&
            upperDiagonal[n - 1 + col - row] == 0) {

            // Place Queen
            board[row][col] = 'Q';

            rowCheck[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            // Recursive Call
            solve(col + 1,
                  board,
                  ans,
                  n,
                  rowCheck,
                  lowerDiagonal,
                  upperDiagonal);

            // Backtrack
            board[row][col] = '.';

            rowCheck[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

int main() {

    int n;
    cin >> n;

    vector<string> board(n);

    string s(n, '.');

    for (int i = 0; i < n; i++) {
        board[i] = s;
    }

    vector<vector<string>> ans;

    map<int,int> rowCheck;
    map<int,int> lowerDiagonal;
    map<int,int> upperDiagonal;

    solve(0,
          board,
          ans,
          n,
          rowCheck,
          lowerDiagonal,
          upperDiagonal);

    // Print all valid arrangements
    for (auto arrangement : ans) {

        for (auto row : arrangement) {
            cout << row << endl;
        }

        cout << endl;
    }

    return 0;
}