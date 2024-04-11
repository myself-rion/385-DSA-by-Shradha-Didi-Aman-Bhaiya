
class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        int diff = 0;

        for (int i = 0; i < n; ++i)
        {
            diff = abs(x - arr[i]);

            if (diff == 0)
                continue;

            pq.push({diff, -arr[i]}); // here I'm using -arr[i] because I'm using maxHeap. So, in priority queue if keys(difference) are equal, it compares based on values.This helps us keep the order ascending in case of numbers with same differences.

            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty())
        {
            ans.push_back(-pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};