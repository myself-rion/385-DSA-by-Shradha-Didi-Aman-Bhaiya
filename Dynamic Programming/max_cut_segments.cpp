int solveMem(int n, int x, int y, int z, vector<int> &dp) // using memorization
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];

    int a = solveMem(n - x, x, y, z, dp) + 1; // when cut the segment in x
    int b = solveMem(n - y, x, y, z, dp) + 1;// when cut the segment in y
    int c = solveMem(n - z, x, y, z, dp) + 1;// when cut the segment in z

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);

    int ans = solveMem(n, x, y, z, dp);

    if (ans < 0)
    {

        return 0;
    }

    else
    {
        return ans;
    }
}
// T.C : O(n)
// S.C : O(n)