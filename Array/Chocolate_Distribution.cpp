Class Solution:
{
public:
    long long min_diff = INT_MAX;
    sort(a, a + n);
    for (auto i = 0; i <= n - m; i++)
    {
        if (a[m + i - 1] - a[i] < min_diff)
        {
            min_diff = a[m + i - 1] - a[i];
        }
    }
    return min_diff;
};