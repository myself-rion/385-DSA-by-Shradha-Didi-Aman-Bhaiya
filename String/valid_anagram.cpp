/*
Intuition: increase the value for one string & decrease for other. If all the values for keys remain 0 at the end then it's an anagram
*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        if (s.length() == 1 && s[0] == t[0])
            return true;
        

        // using hashmaps
        unordered_map<char, int> mp;

        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for(auto i: mp){
            if(i.second>=1) return false;
        }

        return true;
        


        // using constant array space
        int arr[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (arr[i] >= 1)
                return false;
        }

        return true;
    }
};