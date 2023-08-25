// using 2 pointer approach
// T.C: O(nlogn)+ O(n*m)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < k && nums[j] == nums[j - 1]) //to avoid duplicates
                        j++;
                    while (j < k && nums[k] == nums[k + 1]) //to avoid duplicates
                        k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};