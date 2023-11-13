
class Solution
{
public:

    long long int findSubarray(vector<long long int> &arr, int n)
    {
        unordered_map<long long, int> mp; // <sum, frequency>
        long long int sum = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == 0)
                ans++;

            mp[sum]++; //increasing frequency
        }

        for (auto i : mp)
        {
            long long x = i.second;

            ans += x * (x - 1) / 2; //formula: x= frequency of each sum
        }

        return ans;
    }
};