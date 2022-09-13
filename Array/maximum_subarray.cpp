// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current= 0;
        int max_sum= INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            current+= nums[i];
            if(current>max_sum)
            {
                max_sum= current;
            }
            if(current<0)
            {
                current=0;
            }
        }
        return max_sum;
    }
};