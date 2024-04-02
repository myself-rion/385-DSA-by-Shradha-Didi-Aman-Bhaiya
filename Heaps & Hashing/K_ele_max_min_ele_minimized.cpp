class Solution
{
public:
    int minDiff(int arr[], int N, int K)
    {
        sort(arr, arr + N);

        int ans = INT_MAX;

        for (int i = 0; i <= N - K; ++i) 
        {
            ans = min(ans, abs(arr[i] - arr[i + K - 1])); //abs(arr[i] - arr[i + K - 1]) = sliding window to find max & min element in a window
        }
        return ans;
    }
};

/*
T.C: O(nlogn)
S.C: O(1)
*/