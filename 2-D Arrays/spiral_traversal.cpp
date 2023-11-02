class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1; //up= first row, down= last row, left=first col, right=last col

        int dir = 0; //direction of traversal
        vector<int> ans;

        while (up <= down && left <= right)
        {
            switch (dir)
            {
            // right
            case 0:
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(matrix[up][i]);
                }
                up++;
                break;
            // down
            case 1:
                for (int i = up; i <= down; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
                break;
            // left
            case 2:
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
                break;
            case 3:
                // up
                for (int i = down; i >= up; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
                break;
            }
            dir = (dir + 1) % 4;
        }

        return ans;
    }
};