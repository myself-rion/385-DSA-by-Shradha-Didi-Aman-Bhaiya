// intuition : fix target & match, if matched then increase the count else decrease the count
// when count is 0, means equal number of dsitinct elements till now, so update the target
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int target = 0;
        for (auto i : nums)
        {
            if (count == 0)
                target = i;

            if (target == i)
                count++;
            else
                count--;
        }

        return target;
    }
};
// in O(1) space