class Solution
{
public:
    bool isPossible(long long a[], long long b[], int n, long long k)
    {
        sort(a, a + n);
        sort(b, b + n);

        reverse(b, b + n);

        for (long long i = 0; i < n; i++)
        {
            if (a[i] + b[i] >= k)
                continue;
            else
                return false;
        }

        return true;
    }
};