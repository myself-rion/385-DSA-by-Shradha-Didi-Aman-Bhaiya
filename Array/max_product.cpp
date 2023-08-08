// Either product of 3 biggest positive values will be maxProduct or if there are negative values then pick the 2 biggest negative values and multiply with biggest positive value

// Sort the Array and compare above mentioned products
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int temp1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int temp2 = nums[0] * nums[1] * nums[n - 1];
        return max(temp1, temp2);
    }
};