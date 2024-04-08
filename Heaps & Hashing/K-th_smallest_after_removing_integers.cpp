// User function template for C++
class Solution
{
public:
    int kthSmallest(int arr[], int n, int k)
    {
        unordered_set<int> st;

        for(int i=0; i<n; ++i){
            st.insert(arr[i]);
        }

        int num= 1; //first natural number

        while(k>0){
            if(st.find(num)) num++;
            else k--, num++;
        }

        return num-1; //substract to get the kth smallest element
    }
};

// T.C: O(n+k)
// S.C: O(n)