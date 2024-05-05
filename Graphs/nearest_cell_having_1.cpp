//intuition: find dist of 0s from cells having 1

class Solution
{
public:
    // using bfs instead of dfs because we will deal with neighbours level by level
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dist(row, vector<int>(col, 0));
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        queue<pair<pair<int, int>, int>> q; //{row of 1, col of 1}, dist of 1 itself is 0

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j]==1)
                {
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        int dirx[] = {-1, 0, 0, 1};
        int diry[] = {0, 1, -1, 0};

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            dist[r][c] = steps;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nrow = r + dirx[i];
                int ncol = c + diry[i];

                if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = true;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }

        return dist;
    }
};

// T.C = S.C = O(n*m)