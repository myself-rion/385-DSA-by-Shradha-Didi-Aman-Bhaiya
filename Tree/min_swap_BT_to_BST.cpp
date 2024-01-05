// Pre-requisite problem: Min swaps to sort an array
//intuition: inorder of a BST is always sorted
void findInOrder(vector<int> &A, int i, int n, vector<int> &in)
{
    if (i >= n)
        return;

    findInOrder(A, 2 * i + 1, n, in);
    in.push_back(A[i]);
    findInOrder(A, 2 * i + 2, n, in);
}

int minSwapstoSort(vector<int> &in, int n)
{
    vector<pair<int, int>> cmpPairs;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = {in[i], i}; // val, index;
        cmpPairs.push_back(p);
    }

    sort(cmpPairs.begin(), cmpPairs.end());

    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        int index = cmpPairs[i].second;
        if (index != i)
        {
            swaps++;
            swap(cmpPairs[i], cmpPairs[index]);
            i--;
        }
    }
    return swaps;
}

int minSwaps(vector<int> &A, int n)
{
    vector<int> in;
    findInOrder(A, 0, n, in);
    return minSwapstoSort(in, n);
}