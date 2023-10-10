// The intuition is same as 3sum problem

class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        long long ans = 0;
        sort(arr, arr + n);

        for (long long i = 0; i < n - 2; i++)
        {

            long long j = i + 1, k = n - 1;

            while (j < k)
            {
                if (arr[i] + arr[j] + arr[k] >= sum)
                    k--;
                else
                {
                    ans += k - j; //catch: for current position of i & j, number of triplets will be k-j
                    j++;
                }
            }
        }

        return ans;
    }
};