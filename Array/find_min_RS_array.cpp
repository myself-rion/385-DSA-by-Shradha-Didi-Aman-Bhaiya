// using concept of monotonic function & binary search
// updated question of find pivot element in an array

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int low = 0;
        int high = nums.size() - 1;
        int mid = low + (high - low) / 2;
        int ans = 5001;

        while (low <= high)
        {
            if (nums[mid] >= nums[low])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }

            mid = low + (high - low) / 2;
        }

        return ans;
    }
};