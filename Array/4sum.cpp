// User function template for C++

class Solution
{
public:
   
    vector<vector<int>> fourSum(vector<int> &a, int target_sum)
    {
        set<vector<int>> s; //will only store unique index elements
        vector<vector<int>> ans;
        int n = a.size();
        sort(a.begin(), a.end());
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int start = j + 1, end = n - 1; //searching concept
                while (start < end)
                {
                    int sum = a[i] + a[j] + a[start] + a[end];
                    if (sum == target_sum)
                    {
                        vector<int> quadruple = {a[i], a[j], a[start], a[end]};
                        s.insert(quadruple);
                        start++;
                        end--;
                    }
                    else if (sum > target_sum)
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
                }
            }
        }
        for (auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};