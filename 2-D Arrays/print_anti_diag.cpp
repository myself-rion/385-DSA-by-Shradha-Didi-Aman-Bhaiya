class Solution
{

public:
    void traverseDiag(vector<int> &ans, int N, vector<vector<int>> &A, int row, int col, vector<vector<bool>> &visited)
    {
        if (col < 0 || row >= N)
            return;

        if (!visited[row][col])
        {
            ans.push_back(A[row][col]);
            visited[row][col] = true;
            traverseDiag(ans, N, A, row + 1, col - 1, visited);
        }
        else
        {
            return;
        }
    }

    vector<int> downwardDiagonal(int N, vector<vector<int>> A)
    {
        vector<int> ans;
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < N; j++)
            {

                traverseDiag(ans, N, A, i, j, visited);
            }
        }

        return ans;
    }
};