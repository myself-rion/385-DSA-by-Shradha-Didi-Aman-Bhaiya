class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b)
    {

        int count = 0;
        int n = a ^ b; //n= dissimilar number of bits

        while (n > 0)
        {
            if (n & 1) //number of 1s in n is the answer
                count++;
            n >>= 1;
        }

        return count;
    }
};