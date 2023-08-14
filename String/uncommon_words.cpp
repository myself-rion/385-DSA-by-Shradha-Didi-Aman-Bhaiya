class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> ans;
        unordered_map<string, int> mp;

        istringstream s(s1); //splits string into words
        string word1;
        while (s >> word1) //words1 extracting from s
        {
            mp[word1]++;
        }

        istringstream t(s2);
        string word2;
        while (t >> word2)
        {
            mp[word2]++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            string key = it->first;
            int val = it->second;

            if (val == 1)
            {
                ans.push_back(key);
            }
        }
        return ans;
    }
};