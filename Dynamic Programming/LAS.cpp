int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();
    if (n == 1)
        return 1;
    unordered_map<int, int> dp;
    int ans = 0, temp = 0;

    for (int i = 0; i < n; i++)
    {
        temp = arr[i] - difference;
        int tempAns = 0;

        if (dp.find(temp) != dp.end())
            tempAns = dp[temp];

        dp[arr[i]] = 1 + tempAns;

        ans = max(ans, dp[arr[i]]);
    }

    return ans;
}