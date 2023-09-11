// User function template for C++
class Solution
{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    static bool mycompare(string s1, string s2) //comparison function will be static cause every element in the vector will sharen same copy of function
    {
        string XY = s1.append(s2);
        string YX = s2.append(s1);

        return (XY>YX);
    }
    string printLargest(vector<string> &arr)
    {
        string ans = "";
        sort(arr.begin(), arr.end(), mycompare);
        
        for (auto &s : arr)
        {
            ans += s;
        }

        return ans;
    }
};