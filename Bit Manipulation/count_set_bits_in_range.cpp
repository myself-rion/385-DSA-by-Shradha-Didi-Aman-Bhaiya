

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if (n <= 1)
            return n;
        int pow_of_2 = log2(n); // 2^power_of_two

        int num = 1 << pow_of_2; // getting the power of 2 number closest to n i.e: 8 closest to 11

        return ((num / 2) * pow_of_2 + 1) + (n - num) + countSetBits(n - num);
    }
};

/*n=11,so binary numbers from 0-11 are

0000=0
0001=1
0010=2
0011=3
0100=4
0101=5
0110=6
0111=7
1000=8
1001=9
1010=10
1011=11
*note*: po2=power of 2

*note*: total set bits in any po2 is only 1.
NOW,

1)

take the highest po2 less than or equal to the number.

here it is 8.(n=11)

2)

now for any po2, observe the pattern, suppose for 8:

total set bits in right most bit from 0 to 7(8-1) is 4 (8/2), [0,1,0,1,0,1,0,1]

total set bits in 2nd right most bit from 0 to 7 is 4,[0,0,1,1,0,0,1,1]

total set bits in 3rd right most bit from 0 to 7 is 4,[0,0,0,0,1,1,1,1]

and set bits in 8 is 1 (because it is po2).
so for 8= total set bits from 1 to 8 is 3*(8/2)+1=13.
for 16= 4*(16/2)+1=33
and so on.

pattern: total set bits from 1 to any po2= log2(po2)*(po2/2)+1
3)

Now, from 8 to 11 or upward till next po2, all the left most bits will definitely be 1(set bits).

1001→9

1010→10

1011→11

So for 9 to 11, count of all left most set bits is 11-8=3.(n-po2)
Now count is 13+3=16

4)

now recur for 11-8,i.e 3(n-po2)
algo:

totalSetBits(n):

    if n<=1:

        return n

    return (log2(po2)*(po2/2)+1)+(n-po2)+totalSetBits(n-po2)
    */