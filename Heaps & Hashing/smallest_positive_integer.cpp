
class Solution
{
public:

    int missingNumber(int arr[], int n)
    {
        int temp = 0;

        // check if 1 is present in the array or not. If it is not present then 1 is the answer. So,find 1.
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == 1)
            {
                temp = arr[i];
                break;
            }
        }

        if (!temp)
            return 1;

        //change the values of negative integers and numbers >n to 1
        for (int i = 0; i < n; ++i)
            if (arr[i] <= 0 || arr[i] > n)
                arr[i] = 1; // keeping the values in [1,n+1] range because our ans will be in that range

        for (int i = 0; i < n; ++i)
        {
            arr[(arr[i] - 1) % n] += n; // cyclic sort concept
        }

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] <= n)
                return i + 1; // missing number
        }

        return n + 1;
    }
};

/*
T.C: O(N)
S.C: O(1)
*/