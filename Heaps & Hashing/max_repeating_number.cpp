// User function template for C++
class Solution
{
public:
    // Returns maximum repeating element in arr[0..n-1].
    // The array elements are in range from 0 to k-1
    int maxRepeating(int *arr, int n, int k)
    {
        int store[k] = {0};

        for (int i = 0; i < n; ++i)
        {
            store[arr[i]]++;
        }

        return max_element(store, store + k) - store; //max_element returns an iterator & substracting store(base address) from it gives the actual index.
    }
};

/*
T.C: O(n)
S.C: O(k)
*/