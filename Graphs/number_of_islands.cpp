class Solution
{
public:
    // direction array
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool isSafe(vector<vector<char>> &grid, vector<vector<bool>> &vis, int row, int col)
    {
        return (row < grid.size() && col < grid[0].size() && col >= 0 && row >= 0 && grid[row][col] == '1' && !vis[row][col]);
    }

    // using dfs
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int row, int col)
    {
        vis[row][col] = true;

        for (int i = 0; i < 8; ++i)
        {
            int new_row = row + x[i];
            int new_col = col + y[i];

            if (isSafe(grid, vis, new_row, new_col))
            {
                dfs(grid, vis, new_row, new_col);
            }
        }
    }

    // using bfs
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int row, int col)
    {
        vis[row][col] = true;

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 8; ++i)
            {
                int new_row = r + x[i];
                int new_col = c + y[i];

                if (isSafe(grid, vis, new_row, new_col))
                {
                    vis[new_row][new_col] = true;
                    q.push({new_row, new_col});
                }
            }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0, row = grid.size(), col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1' && vis[i][j] == false)
                {
                    ans++;
                    bfs(grid, vis, i, j);
                }
            }
        }

        return ans;
    }
};

// T.C: O(N^2)
// S.C: O(N^2)