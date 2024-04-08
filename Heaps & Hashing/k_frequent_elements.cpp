// using max heap & comparator function
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> ump;

        for (auto &i : nums)
        {
            ump[i]++;
        }

        auto comp = [](const auto &x, const auto &y)
        { return x.second < y.second; }; // max heap condition because the priority goes to second element “y”
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(ump.begin(), ump.end(), comp);

        vector<int> ans;

        while (k--)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};

// using min heap

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        for (auto &it : m)
        {
            p.push({it.second, it.first});
            if (p.size() > k)
                p.pop();
        }
        vector<int> ans;
        while (k--)
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};

// T.C: O(nlogk)