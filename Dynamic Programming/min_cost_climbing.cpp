int solve(vector<int> &cost, int k, vector<int> &dp)
{ // memorization method
    if (k <= 1)
        return cost[k];

    if (dp[k] != -1)
    {
        return dp[k];
    }

    dp[k] = cost[k] + min(solve(cost, k - 1, dp), solve(cost, k - 2, dp));
    return dp[k];
}

int solve2(vector<int> &cost, int k)
{ // tabulation method
    vector<int> dp(k + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < k; i++)
    {
        dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
    }

    return min(dp[k - 1], dp[k - 2]);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    // vector<int> dp(n+1, -1); //memorization

    // int ans= min(solve(cost,n-1,dp), solve(cost, n-2, dp));

    int ans = solve2(cost, n);
    return ans;
}

// T.C : O(N)
// S.C: for solve1 O(n)+ O(n)
// S.C: for solve2 O(n)