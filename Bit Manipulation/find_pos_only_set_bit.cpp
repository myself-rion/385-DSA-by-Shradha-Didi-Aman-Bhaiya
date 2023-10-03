class Solution
{
public:
    int findPosition(int N)
    {
        if (N == 0)
            return -1;
        if ((N & N - 1) == 0)
            return log2(N) + 1;
        return -1;
    }
};