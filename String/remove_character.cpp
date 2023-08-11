string removeChars(string string1, string string2)
{
    string s = "";

    map<char, int> mp;

    for (int i = 0; i < string2.size(); i++)
    {
        mp[string2[i]] = 1;
    }

    for (int i = 0; i < string1.length(); i++)
    {
        if (mp[string1[i]] != 1)
        {
            s.push_back(string1[i]);
        }
    }

    return s;
}