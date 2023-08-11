/*
The solution first sorts the input vector of strings using the sort() function from the library. Sorting the array arranges the strings lexicographically so that the first and last strings will have the most dissimilar characters. This is because the common prefix must be shared among all strings in the input, and so the first and last strings must share the most characters in common.
*/
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string s = "";
        sort(strs.begin(), strs.end()); // lexicographical sorting
        string start = strs[0];
        string end = strs[strs.size() - 1];
        for (int i = 0; i < min(start.length(), end.length()); i++)
        {
            if (start[i] != end[i])
                return s;
            else
                s.push_back(start[i]);
        }
        return s;
    }
};