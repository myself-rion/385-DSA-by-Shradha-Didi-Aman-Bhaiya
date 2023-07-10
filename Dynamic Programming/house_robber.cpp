int optimal_sol(vector<int> &arr, int n)
{

    if (n < 0)
        return 0;

    int previous_pointer2 = 0;
    int previous_pointer1 = arr[0];

    for (int i = 1; i < n; i++)
    {
        int in = arr[i] + previous_pointer2; //either include the current item
        int ex = previous_pointer1; //or exclude

        int ans = max(in, ex);

        previous_pointer2 = previous_pointer1;
        previous_pointer1 = ans;
    }

    return previous_pointer1;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    return optimal_sol(nums, n);
}
//TC: O(N), SC: O(1)