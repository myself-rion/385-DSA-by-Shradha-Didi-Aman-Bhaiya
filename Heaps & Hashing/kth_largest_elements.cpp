// User function template for C++
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        vector<int> ans;
        priority_queue<int> pq;

        for (int i = 0; i < n; ++i)
        {
            pq.push(arr[i]);
        }

        while (k--)
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

//T.C: O(nlogk)