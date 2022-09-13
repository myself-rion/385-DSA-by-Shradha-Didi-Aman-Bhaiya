class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        map<int,int> m; // creating a map of int key & int values
        for(int i=0;i< nums.size(); i++)
        {
            m.insert({nums[i], i});  //.insert() done in O(logn) time
        }
        auto it= m.find(target);  //.find() returns an iterator if found. else returns .end()
        if(it==m.end())
        {
            return -1;
        }
        else{
            return it->second;
        }
    }
    };
