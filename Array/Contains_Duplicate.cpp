class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto ele : nums)
        {
            s.insert(ele);
        }
        if(nums.size() == s.size())
        {
            return false;
        }
        return true;
    }
};