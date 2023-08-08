//intuition ---->
/*
number of elements in Nth row = N
Value of a column in Nth row = nCc;
*/

class Solution
{
public:
    vector<int> generateRow(int row)
    {
        vector<int> ans;
        long long temp = 1;
        ans.push_back(temp);
        for (int col = 1; col < row; col++)
        {
            temp = temp * (row - col);
            temp = temp / col;
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};