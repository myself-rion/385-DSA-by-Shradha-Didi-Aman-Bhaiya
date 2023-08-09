class Solution
{
public:
    int checkHappy(int num) //to sum the digits
    {
        int rem = 0;
        int sum = 0;

        while (num > 0)
        {
            rem = num % 10;
            sum = sum + (rem * rem);
            num = num / 10;
        }

        return sum;
    }
    bool isHappy(int num)
    {
        int temp = num;
        while (1)
        {
            if (temp == 89) //if sum of digits ends with 89 then it will stuck in infinite loop
                return false;
            else if (temp == 1)
                return true;
            else
                temp = checkHappy(temp);
        }
    }
};