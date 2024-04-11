class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        unordered_map<int, int> ump; //{sum, index}

        int sum = 0, temp_len = 0, max_len = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += A[i];
            if (sum == 0) //when the sum becomes zero at a particular index
                max_len = max(max_len, i + 1); 

            if (ump.find(sum) != ump.end()) //between two same sums the subarray becomes 0
            {
                temp_len = i - ump[sum];
                max_len = max(max_len, temp_len);
            }
            else
                ump[sum] = i;
        }

        return max_len;
    }
};

/*
T.C: O(n);
S.C: O(n)
*/