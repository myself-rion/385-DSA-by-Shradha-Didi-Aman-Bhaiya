
class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        unordered_map<int, int> ump;
        vector<int> ans;

        for (int i = 0; i < k; ++i) //count all the frequencies in first window of size K
        {
            ump[A[i]]++;
        }

        ans.push_back(ump.size());

        for (int j = k; j < n; ++j) // sliding window
        {
            ump[A[j - k]]--; //removing element from left side

            if (!ump[A[j - k]]) //element frequency=0 
                ump.erase(A[j - k]);

            ump[A[j]]++;
            ans.push_back(ump.size());
        }

        return ans;
    }
};

/*
T.C: O(n)
S.C: O(n)
*/