
// c++ inbuilt function isupper() can be used to find uppercase letters
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.length() == 1)
            return true;

        int count = 0;

        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
                count++;
        }

        if (count == 1 && (word[0] >= 'A' && word[0] <= 'Z')) //case 1 : First letter capital & rest are lowercase, eg: Google
            return true;

        else if (count == 0 || count == word.length())  //case 2 : All are lowercase OR all are Uppercase
            return true;

        else //case 3 : eg: FlaG
            return false;
    }
};