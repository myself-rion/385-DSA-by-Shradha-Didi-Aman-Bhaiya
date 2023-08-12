// Sequel of find unique element in an Array
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        if (s.length() == 0)
            return t[0];

        char ans = '\0';

        for (auto i : s)
            ans ^= i;
        for (auto i : t)
            ans ^= i;

        return ans;
    }
};