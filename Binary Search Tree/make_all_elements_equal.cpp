class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        int start = 0, end = n - 1;
        int ans = 0;
        sort(nums.begin(), nums.end());

        while (start <= end)
        {
            ans += nums[end] - nums[start]; //formula
            start++, end--;
        }

        return ans;
    }
};