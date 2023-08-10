string removeConsecutiveCharacter(string S)
{
    string s = "";
    s += S[0];
    for (int i = 1; i < S.length(); i++)
    {
        if (S[i] != S[i - 1])
            s += S[i];
    }

    return s;
}