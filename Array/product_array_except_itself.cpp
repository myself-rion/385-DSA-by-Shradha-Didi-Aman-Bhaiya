vector<int> productExceptSelf(vector<long long int> &nums, int n)
{

    // code here
    int temp = 1;
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++) //from left to right, ans[i] stores the total product of its left part
    {
        ans[i] = temp;
        temp *= nums[i];
    }

    temp = 1;

    for (int i = n - 1; i >= 0; i--) //from right to left, ans[i] stores the total product of its right part
    {
        ans[i] = ans[i] * temp;
        temp *= nums[i];
    }

    return ans;
}