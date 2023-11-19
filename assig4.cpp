#include <bits/stdc++.h>
using namespace std;
bool isSafe(int r, int c, vector<string> &board, int n)
{
    // upper left
    int i = r, j = c;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    // lower left;
    i = r;
    j = c;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')

            return false;
        i++;
        j--;
    }
    // left
    i = r;
    j = c;
    while (j >= 0)
    {
        if (board[i][j] == 'Q')

            return false;
        j--;
    }
    // upperright;
    i = r;
    j = c;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 'Q')

            return false;
        j++;
        i--;
    }

    // lower right;
    i = r;
    j = c;
    while (i < n && j < n)
    {
        if (board[i][j] == 'Q')

            return false;
        i++;
        j++;
    }
    // right
    i = r;
    j = c;
    while (j < n)
    {
        if (board[i][j] == 'Q')

            return false;
        j++;
    }
    return true;
}
void solve(int col, int col1, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    if (col == col1)
    {
        solve(col + 1, col1, board, ans, n);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, board, n))
        {
            board[i][col] = 'Q';
            solve(col + 1, col1, board, ans, n);
            board[i][col] = '.';
        }
    }
}
int main()
{
    int n = 7;
    vector<string> bd(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        bd[i] = s;
    }
    vector<vector<string>> ans;
    int r = 4, c = 2;
    bd[r][c] = 'Q';
    solve(0, c, bd, ans, n);
    if (ans.size() == 0)
    {
        cout << "no possible combination!!\n";
        return 0;
    }
    for (auto &board : ans)
    {
        for (auto &x : board)
        {
            cout << x << endl;
        }
        cout << endl;
    }
}

/*
Here's a brief explanation of why TC is  O(N!):

In the first row, you have N choices for placing the first queen.
In the second row, you can't place the queen in the same column as the first queen, so you have N-1 choices.
In the third row, you can't place the queen in the same column as the first two queens, so you have N-2 choices.
This pattern continues until you place all N queens.


*/