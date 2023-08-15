class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans;
        ans.push_back(s[0]);
        int i = 1;

        for (int i = 1; i < s.length(); i++)
        {

            if (!ans.empty())
                (s[i] == ans.back()) ? ans.pop_back() : ans.push_back(s[i]);
            else
                ans.push_back(s[i]);
        }

        return ans;
    }
};