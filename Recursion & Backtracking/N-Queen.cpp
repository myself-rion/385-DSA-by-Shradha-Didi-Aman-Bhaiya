class Solution
{
public:
    bool isSafe(int c, int r, vector<string> board, int n)
    {
        // only check upper left diagonal, left, lower down diagonal because the right side of the queen isn't visited

        int col = c, row = r;
        while (row >= 0 && col >= 0) // upper left diagonal
        {
            if (board[row][col] == 'Q')
                return false;
            row--, col--;
        }
        col = c, row = r;

        while (col >= 0) // checking left side in same row
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        col = c, row = r;
        while (row < n && col >= 0) // lower left diagonal
        {
            if (board[row][col] == 'Q')
                return false;
            row++, col--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<string> &board,
               int n) //checking for each column
    {
        if (col == n)
        { // base case
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; ++row)
        {
            if (isSafe(col, row, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);

                board[row][col] = '.'; // backtracking
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');

        for (int i = 0; i < n; ++i)
        {
            board.push_back(s);
        }

        solve(0, ans, board, n);
        return ans;
    }
};

//T.C: O(N!)