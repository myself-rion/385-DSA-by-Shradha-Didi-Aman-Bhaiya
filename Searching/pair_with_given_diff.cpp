

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);

    int i = 0, j = 1;

    while (i < size && j < size)
    {
        if (i != j && arr[j] - arr[i] == n)
            return true;
        else if (arr[j] - arr[i] > n)
            i++;
        else
            j++;
    }

    return false;
}