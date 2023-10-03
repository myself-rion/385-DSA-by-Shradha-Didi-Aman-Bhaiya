class Solution
{
public:
    int setBits(int N)
    {
        int count = 0;
        // while (N > 0)
        // {
        //     if (N & 1) checks the LSB
        //         count++;
        //     N = N >> 1;
        // }

        while (N>0)
        {
            N=N&(N-1);
            count++;
        }
        
        return count;
    }
};