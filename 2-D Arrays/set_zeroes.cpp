class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool flag1 = false, flag2 = false;

        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++) //checking if any 0 exists in first col
        {
            if (matrix[i][0] == 0)
            {
                flag1 = !flag1;
                break;
            }
        }

        for (int j = 0; j < m; j++) //checking if any 0 exists in first row
        {
            if (matrix[0][j] == 0)
            {
                flag2 = !flag2;
                break;
            }
        }

        // using first row & col as record arrays
        for (int i = 1; i < n; i++) 
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // fetching details from record arrays & putting 0s in correct places
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // if there was any 0 in first col then changing all the values in first col to 0
        if (flag1)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }

        // if there was any 0 in first row then changing all the values in first col to 0
        if (flag2)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};

// T.C: O(nm)
// S.C: O(1)