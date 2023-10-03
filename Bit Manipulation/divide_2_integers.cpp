// User function Template for C++

class Solution
{
public:
    long long divide(long long dividend, long long divisor)
    {
        int find_sign = ((dividend >= 0) ^ (divisor >= 0)) ? 0 : 1; //0 means both are opposite signs, 1 means both are samem signed

        dividend = abs(dividend); //getting the absolute value
        divisor = abs(divisor);

        long long quotent = 0;

        for (long long i = 31; i >= 0; i--)
        { // 31 means 2^31
            if ((divisor << i) <= dividend)
            {
                dividend -= divisor << i;
                quotent += 1LL << i;
            }
        }

        if (find_sign)
            return quotent;
        else
            return -quotent;
    }
};