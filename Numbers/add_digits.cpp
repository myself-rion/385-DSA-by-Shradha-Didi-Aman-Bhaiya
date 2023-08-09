class Solution
{
public:
    int addDigits(int num)
    {
        return 1 + (num - 1) % 9;
    }
};
// Explanation here:  https://leetcode.com/problems/add-digits/solutions/1754049/easy-o-1-explanation-with-example/