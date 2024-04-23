class Solution
{
public:
    void solve(vector<int> &arr, vector<int> &ans, int sum, int idx, int n)
    {
        if (idx == n)
        {
            ans.push_back(sum);
            return;
        }

        solve(arr, ans, sum + arr[idx], idx + 1, n); // take the current element
        solve(arr, ans, sum, idx + 1, n);            // ignore the current element
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        int sum = 0;
        solve(arr, ans, sum, 0, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// T.C: O(2^n)