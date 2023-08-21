/*
Intuition: pick a character & expand its left & right

*/


string longestPalindrome(string s)
{
    string st;
    int max_len = 0;
    int len_l, len_r; //len_l/r= leftmost/rightmost index of the palindrome

    // for odd length of string
    for (int i = 0; i < s.length(); i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            if (r - l + 1 > max_len) // rightmost index & leftmost index difference = length of the palindromic substring
            {
                len_l = l;
                len_r = r;
                max_len = r - l + 1;
            }
            l--, r++;
        }
    }

    // for even length of string
    for (int i = 0; i < s.length(); i++)
    {
        int l = i, r = i + 1;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            if (r - l + 1 > max_len)
            {
                len_l = l;
                len_r = r;
                max_len = r - l + 1;
            }
            l--, r++;
        }
    }

    for (int i = len_l; i <= len_r; i++)
    {
        st.push_back(s[i]);
    }
    return st;
}