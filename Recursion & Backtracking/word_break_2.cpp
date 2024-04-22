// User function Template for C++

class Solution
{
public:
    void solveProb(int idx, string s, string sentence, vector<string> &dict, vector<string> &ans)
    {
        if (idx == s.length())
        {
            sentence.pop_back(); //removing the " " in last word
            ans.push_back(sentence);
            return;
        }

        string temp = "";
        for (int i = idx; i < s.length(); i++)
        {
            temp = s.substr(idx, i - idx + 1); //overwrites temp in each iteration

            if (find(dict.begin(), dict.end(), temp) != dict.end())
            {

                solveProb(i + 1, s, sentence + temp + " ", dict, ans);

                // backtracking //
            }
        }
    }
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        vector<string> ans;
        solveProb(0, s, "", dict, ans);
        return ans;
    }
};