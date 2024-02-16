class Solution
{
private:
    void solve(vector<int> &can, vector<int> &temp,
               vector<vector<int>> &res, int target, int index)
    {
        if (target == 0)
        {
            res.push_back(temp);
        }
        else if (target < 0)
            return;

        while (index < can.size())
        {
            temp.push_back(can[index]);

            solve(can, temp, res, target - can[index], index);
            index++;

            temp.pop_back(); //backtracking
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<vector<int>> result;

        sort(begin(candidates), end(candidates));

        solve(candidates, temp, result, target, 0);

        temp.clear();

        return result;
    }
};