class Solution
{
public:
    vector<int> kthLargest(int k, int arr[], int n)
    {

        vector<int> ans;

        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        for (int i = 0; i < n; ++i)
        {
            pq.push(arr[i]);

            if (pq.size() < k)
                ans.push_back(-1); //until the heap is of size k, the default ans will be -1
            else
            {
                while (pq.size() > k) pq.pop();
                
                ans.push_back(pq.top()); //the min among k numbers is the kth largest number
            }
        }

        return ans;
    }
};