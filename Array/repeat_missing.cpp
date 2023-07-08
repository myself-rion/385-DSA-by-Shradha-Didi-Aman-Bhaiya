vector<int> findTwoElement(vector<int> arr, int size)
{
    long long n = size;
    // S-Sn = x-y
    // M-Mn = x^2-y^2
    long long S = (n * (n + 1)) / 2; // sum of 1 to N
    long long M = (n * (n + 1) * (2 * n + 1)) / 6;
    long long Sn = 0;
    long long Mn = 0;

    for (long long i = 0; i < n; i++)
    {
        Sn += arr[i];
        Mn += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = Sn - S;
    long long val2 = Mn - M;

    val2 = val2 / val1; // x+y

    long long x = (val1 + val2) / 2; // x is the repeating number
    long long y = val2 - x;          // val2= x+y ---> y=val2-x || y is the missing number

    return {int(x), int(y)};
}