class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> res;

        for (char ch : words[0]) //traversing each letter of 1st word
        {
            bool common = true;

            for (int i = 1; i < words.size(); i++) //checking if the letter is present in other words as well
            {
                if (words[i].find(ch) == string::npos) //string::npos is equivalent to .end()
                {
                    common = false;
                    break;
                }
                else
                {
                    words[i].erase(words[i].find(ch), 1);
                }
            }

            if (common)
                res.push_back(string(1, ch)); //converting character into string
        }

        return res;
    }
};