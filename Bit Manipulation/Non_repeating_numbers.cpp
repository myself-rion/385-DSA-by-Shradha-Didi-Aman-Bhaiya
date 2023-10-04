/* 1. The problem arises how to get the two numbers from its xor.

2.Here is the solution that we will find the rightmostset bit and apply & operation with all the elements and divide the elements into two parts : one which gives gives 0 with the & operation and other one which doesn't. Main point is that the ans (means those two numbers) is never be on same side.

3.Then if i do xor operation of the two parts i can see that the i get the two numbers from two parts .... which is the answer.*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        int xXORy = 0;

        for (int it : nums)
        {
            xXORy ^= it;
        }

        int right_most_setbit = xXORy & -xXORy;

        int x = 0;
        int y = 0;

        for (int it : nums)
        {
            if (it & right_most_setbit)
            {
                x ^= it;
            }
            else
            {
                y ^= it;
            }
        }

        if (x > y)
            return {y, x};
        else
            return {x, y};
    }
};