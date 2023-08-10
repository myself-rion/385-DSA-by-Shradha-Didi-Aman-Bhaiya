// sliding window using 2 pointer approach
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, n = s.length(), ans = 0;
        unordered_set<char> se;

        while (i < n && j < n)
        {
            if (se.find(s[j]) == se.end())
            {
                se.insert(s[j++]);
                ans = max(ans, j - i);
            }
            else
            {
                se.erase(s[i++]);
            }
        }

        return ans;
    }
};