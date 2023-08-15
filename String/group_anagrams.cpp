class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, vector<string>> mp;

        vector<vector<string>> ans;

        for (auto &st : strs)
        {
            string temp = st;
            sort(temp.begin(), temp.end()); //anagrams always generates the same sorting string, eg: mp[aet]= {eat,ate,tea}

            mp[temp].push_back(st);
        }

        for (auto &i : mp)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};