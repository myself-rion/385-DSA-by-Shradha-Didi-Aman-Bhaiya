int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    int maxLen = INT_MIN, rem = 0, sum = 0;
    unordered_map<int, int> mp;
    mp.insert({0, -1});

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        rem = ((sum % k) + k) % k; // will handle negative values as well

        if (mp.find(rem) != mp.end())
        {
            maxLen = max(maxLen, i - mp[rem]);
        }
        else
        {
            mp.insert({rem, i});
        }
    }

    if (maxLen == INT_MIN)
        return 0;

    return maxLen;
}