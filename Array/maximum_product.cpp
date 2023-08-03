class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int curr = 1;

        for (auto i : nums)
        {
            curr *= i;

            if (curr > maxi)
            {
                maxi = curr;
            }

            if (curr == 0)
                curr = 1;
        }

        curr = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            curr *= nums[i];

            if (curr > maxi)
            {
                maxi = curr;
            }

            if (curr == 0)
                curr = 1;
        }
        return maxi;
    }
};