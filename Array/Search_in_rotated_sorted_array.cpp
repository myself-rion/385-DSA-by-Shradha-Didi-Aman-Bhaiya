class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        map<int,int> m;
        for(int i=0;i< nums.size(); i++)
        {
            m.insert({nums[i], i});
        }
        auto it= m.find(target);
        if(it==m.end())
        {
            return -1;
        }
        else{
            return it->second;
        }
    }
    };