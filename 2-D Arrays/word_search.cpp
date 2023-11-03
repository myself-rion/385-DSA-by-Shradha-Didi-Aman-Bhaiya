class Solution
{
public:
    bool searchTheWord(vector<vector<char>> &board, string word, int i, int j, int row, int col, int k)
    {
        if (k >= word.size())
            return true;
        if (i < 0 || i >= row || j < 0 || j >= col || word[k] != board[i][j] || board[i][j] == '.')
            return false;
        if ((word.size() == 1 && board[i][j] == word[k]))
            return true;

        board[i][j] = '.'; //marking as visited
        bool temp = false;
        int x[] = {1, 0, 0, -1}; //down, right, left, up
        int y[] = {0, 1, -1, 0};

        for (int index = 0; index < 4; index++)
        {
            temp = temp | searchTheWord(board, word, i + x[index], j + y[index], row, col, k + 1);
        }

        board[i][j] = word[k]; //backtracking
        return temp;
    }
    bool exist(vector<vector<char>> &board, string word)
    {

        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) //searching for the first letter in matrix
        {
            for (int j = 0; j < m; j++)
            {
                if (word[0] == board[i][j])
                {
                    if (searchTheWord(board, word, i, j, n, m, 0))
                        return true;
                }
            }
        }

        return false;
    }
};