// gap method / shell sort

class Solution
{

    void swapElements(long long arr1[], long long arr2[], int index1, int index2)
    {
        if (arr1[index1] > arr2[index2])
        {
            swap(arr1[index1], arr2[index2]);
        }
    }

public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int len = (n + m);
        int gap = (len / 2) + (len % 2); // gettng the ceiling value. eg: 4.5->5

        int left;
        int right;
        while (gap > 0)
        {

            left = 0;
            right = left + gap;

            while (right < len)
            {

                // arr1 & arr2
                if (left < n && right >= n)
                {
                    swapElements(arr1, arr2, left, right - n); //right-n = original index in arr2,
                }
                // arr2 & arr2
                else if (left >= n)
                {
                    swapElements(arr2, arr2, left - n, right - n); //substracting n to find left & right index in arr2
                }
                // arr1 & arr1
                else
                {

                    swapElements(arr1, arr1, left, right);
                }

                left++, right++;
            }
            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};