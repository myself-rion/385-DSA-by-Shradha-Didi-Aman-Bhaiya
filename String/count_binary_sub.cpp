// Intuition : Group 0,1 consecutively & take the min from the group & add to the sum.
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int prev = 0, curr = 1, sum = 0;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                curr++;
            else
            {
                sum += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        sum += min(prev, curr);
        return sum;
    }
};