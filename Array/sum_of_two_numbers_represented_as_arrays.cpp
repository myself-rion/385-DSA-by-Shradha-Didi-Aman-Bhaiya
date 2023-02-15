class Solution
{
public:
    vector<int> findSum(vector<int> &a, vector<int> &b)
    {
        // code here
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        int sum = 0;
        int digit = 0;
        vector<int> ans;
        while (i >= 0 || j >= 0 || carry != 0)
        {
            int val1 = 0;
            if (i >= 0)
            {
                val1 = a[i];
            }
            int val2 = 0;
            if (j >= 0)
            {
                val2 = b[j];
            }

            sum = carry + val1 + val2;
            digit = sum % 10;
            carry = sum / 10;
            ans.push_back(digit);
            if (i >= 0)
                i--;
            if (j >= 0)
                j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};