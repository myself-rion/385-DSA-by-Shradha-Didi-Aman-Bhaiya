int solveMem(int maxW, int wt[], int val[], int index, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {

        if (maxW - wt[0] >= 0)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][maxW] != -1)
        return dp[index][maxW];

    int include = 0;
    // include

    if (maxW >= wt[index])
    {
        include = val[index] + solveMem(maxW - wt[index], wt, val, index - 1, dp);
    }

    int exclude = solveMem(maxW, wt, val, index - 1, dp);

    dp[index][maxW] = max(include, exclude);
    
    return dp[index][maxW];
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n , vector<int>(W + 1, -1)); // dp[index][maxWeight]
    return solveMem(W, wt, val, n - 1, dp);
}