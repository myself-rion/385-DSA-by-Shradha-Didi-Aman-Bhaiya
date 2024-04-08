class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        if (n == 1)
            return {-1};

        vector<long long> ans(n, -1);
        stack<long long> st;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[i] >= st.top())
            {
                st.pop();
            }

            ans[i] = (st.empty()) ? -1 : st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

/*
T.C: O(N)
S.C: O(N)
*/