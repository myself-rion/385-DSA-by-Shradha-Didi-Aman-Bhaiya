#define mod 1000000007
class Solution
{
public:
    long long add(long x, long y)
    {
        return ((x % mod) + (y % mod)) % mod;
    }

    long long mul(long x, long y)
    {
        return ((x % mod) * (y % mod)) % mod;
    }

    long long solveMem(long long n, long long k, vector<long long> &dp)
    {

        if (n == 1)
            return k;
        if (n == 2)
            return add(k, mul(k, k - 1));

        if (dp[n] != -1)
            return dp[n];

        long long ans = add(mul(solveMem(n - 2, k, dp), k - 1), mul(solveMem(n - 1, k, dp), k - 1));

        dp[n] = ans;

        return dp[n];
    }

    long long countWays(int n, int k)
    {
        vector<long long> dp(n + 1, -1);
        return solveMem((long long)n, (long long)k, dp);
    }
};