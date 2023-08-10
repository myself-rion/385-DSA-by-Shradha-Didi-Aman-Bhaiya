class Solution
{
public:
    bool isPalindrome(string s)
    {
        string neW = "";
        for (auto ch : s)
        {
            if (isalnum(ch)) //isalnum() function to check alphanumeric characters
            {
                neW += tolower(ch); //converting into lowercase characters
            }
        }
        int i = 0;
        int j = neW.length() - 1;

        while (i < j)
        {
            if (neW[i] != neW[j])
                return false;
        }

        return true;
    }
};