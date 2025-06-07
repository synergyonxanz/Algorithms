#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    // check the row
    for (int i = 0; i <= col; i++)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    int row1 = row;
    int col1 = col;

    // checking int the north west direction
    while (row1 >= 0 && col1 >= 0)
    {
        if (board[row1][col1] == 'Q')
            return false;
        row1--;
        col1--;
    }

    row1 = row;
    col1 = col;
    // checking the south west direction
    while (row1 < n && col1 >= 0)
    {
        if (board[row1][col1] == 'Q')
            return false;
        row1++;
        col1--;
    }

    return true;
}

void solve(vector<vector<string>> &ans, vector<string> &board, int col, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            solve(ans, board, col + 1, n);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(ans, board, 0, n);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << endl;
        }
        cout << endl;
    }
    cout << ans.size();
    return 0;
}