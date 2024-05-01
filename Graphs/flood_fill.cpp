class Solution
{
public:
    int x[4] = {-1, 0, 0, 1};
    int y[4] = {0, 1, -1, 0};

    void dfs(vector<vector<int>> &image, int r, int c, int &col, int &pixel_val)
    {
        if (r < 0 || r >= image.size() || c < 0 || c > image[0].size() ||
            image[r][c] == col || image[r][c] != pixel_val)
            return;

        image[r][c] = col;

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + x[i];
            int nc = c + y[i];

            dfs(image, nr, nc, col, pixel_val);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int pixel_val = image[sr][sc];

        dfs(image, sr, sc, color, pixel_val);

        return image;
    }
};

// T.C: O(N^2);
// S.C: O(N)