// User function Template for C++
class Solution
{
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<char>> &mat, int dirx[], int diry[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dirx[i];
            int ncol = col + diry[i];
            
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, mat, dirx, diry);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m,
                              vector<vector<char>> mat)
    {
        int dirx[] = {-1, 0, +1, 0};
        int diry[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));


        // traverse first row and last row
        for (int j = 0; j < m; j++)
        {
            // check for unvisited Os in the boundary rows
            
            if (!vis[0][j] && mat[0][j] == 'O')
            {
                dfs(0, j, vis, mat, dirx, diry);
            }

            
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j, vis, mat, dirx, diry);
            }
        }

        for (int i = 0; i < n; i++)
        {
            // check for unvisited Os in the boundary columns
            
            if (!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(i, 0, vis, mat, dirx, diry);
            }

            
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1, vis, mat, dirx, diry);
            }
        }

        // if unvisited O then convert to X
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};

// T.C= S.C= O(n*m)