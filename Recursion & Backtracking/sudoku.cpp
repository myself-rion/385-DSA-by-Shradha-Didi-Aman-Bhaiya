class Solution
{
public:
    bool isPossible(int row, int col, int num, int grid[N][N])
    {
        for (int i = 0; i < 9; ++i)
        {
            int g_row = (3 * (row / 3) + i / 3), g_col = (3 * (col / 3) + i % 3); //finding the 3x3 grid based upon the row & col

            if (grid[row][i] == num)
                return false;
            if (grid[i][col] == num)
                return false;
            if (grid[g_row][g_col] == num)
                return false;
        }

        return true;
    }

    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {

                if (grid[i][j] == 0)
                {

                    for (int num = 1; num <= 9; ++num)
                    {
                        if (isPossible(i, j, num, grid))
                        {
                            grid[i][j] = num;

                            if (SolveSudoku(grid)) //checks possible solution after inserting the current value
                                return true;
                            else
                            {
                                grid[i][j] = 0; // backtracking
                            }
                        }
                    }

                    return false; //when you couldn't insert any number in the empty cell
                }
            }
        }

        return true; //all cells are filled
    }
};