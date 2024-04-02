// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i) //building a max heap
    {
        int root_element = i;
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;

        if (left_child < n && arr[left_child] > arr[root_element])
        {
            root_element = left_child;
        }

        if (right_child < n && arr[right_child] > arr[root_element])
        {
            root_element = right_child;
        }

        if (root_element != i) //means we have found a node which is greater than root node
        {
            swap(arr[root_element], arr[i]);
            heapify(arr, n, root_element); //heapify the newly formed heap again
        }
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; --i) //starting i from (n/2 -1) because n/2 to n elements are leaf elements & leaf elements are heap themselves
        {
            heapify(arr, n, i);
        }
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; --i)
        {
            swap(arr[0], arr[i]); //arr[0] contains the max element
            heapify(arr, i, 0); //heapify after swapping
        }
    }
};


/*T.C: O(nlogn)
S.C: O(1)*/