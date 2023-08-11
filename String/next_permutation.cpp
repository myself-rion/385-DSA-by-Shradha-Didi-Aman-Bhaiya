/*
Intuition : the next permutation value has to be just greater than the current order.
eg:arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}

Algorithm: 
i)find the breakpoint(where an element has higher value at right)
ii) swap just greater element than the arr[breakpoint]
iii) reverse from arr[breakpoint+1] to arr[end];

*/

vector<int> nextPermutation(int N, vector<int> &arr)
{
    int index = -1;
    // find breakpoint
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i - 1] < arr[i])
        {
            index = i - 1;
            break;
        }
    }

    // means we are at the highest order permutation & the next permutation would be the smallest one
    // eg: {5,4,3,2,1} --> {1,2,3,4,5}
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // swap just greater element than arr[index]
    for (int i = N - 1; i >= index; i--)
    {
        if (arr[index] < arr[i])
        {
            swap(arr[index], arr[i]);
            break;
        }
    }

    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}