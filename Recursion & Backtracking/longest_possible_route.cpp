// User function Template for C++

class Solution
{
    int solve(vector<vector<int>> &matrix, vector<vector<bool>> &vis, int i, int j, int dx, int dy, int row, int col)
    {
        if (i < 0 || i >= row || j < 0 || j >= col || vis[i][j] == true || matrix[i][j] == 0)
            return 0;

        if (i == dx && j == dy) //reached destination
            return 1;

        vis[i][j] = true;

        // int dist=0;
        int up = solve(matrix, vis, i - 1, j, dx, dy, row, col);
        int down = solve(matrix, vis, i + 1, j, dx, dy, row, col);
        int left = solve(matrix, vis, i, j - 1, dx, dy, row, col);
        int right = solve(matrix, vis, i, j + 1, dx, dy, row, col);

        int dist = max({up, down, left, right});

        vis[i][j] = false; // backtrackihng

        return (dist > 0) ? dist + 1 : 0; //if(dist>0) return dist+1, else return 0;
    }

public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false)); //visiting vector

        return solve(matrix, vis, xs, ys, xd, yd, row, col) - 1; //distance between source & destination that's why substracting 1
    }
};