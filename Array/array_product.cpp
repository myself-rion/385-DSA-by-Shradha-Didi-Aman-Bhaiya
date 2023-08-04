class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 1);

        int pre = 1;  // track previous record
        int post = 1; // track post record

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = pre;
            pre = pre * nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] *= post; //left value* right value
            post = post * nums[i];
        }

        return ans;
    }
};
// T.C: O(N)
// S.C: O(1)