// User function Template for C++

class Solution
{
public:
    // Function to arrange all letters of a string in lexicographical
    // order using Counting Sort.
    string countSort(string arr)
    {
        string ans = "";
        int hash[26] = {0};

        for (auto it : arr)
        {
            hash[it - 'a']++;
        }

        int j = 0;

        while (j < 26)
        {
            if (hash[j] > 0)
            {
                ans += char(j + 97);
                hash[j]--;
            }
            else
            {
                j++;
            }
        }

        return ans;
    }
};