class Solution {
    public :
        long long int merge(vector<long long> & nums, long long low, long long mid, long long high){
            long long count = 0, k = 0;
int l = low, r = mid + 1, size = high - low + 1;
vector<long long> sorted(size);

while (l <= mid and r <= high)
{
    if (nums[l] <= nums[r])
    {
        sorted[k++] = nums[l++];
    }
    else
    {
        sorted[k++] = nums[r++];
        count = count + (mid - l + 1);
    }
}
while (l <= mid)
{
    sorted[k++] = nums[l++];
}
while (r <= high)
{
    sorted[k++] = nums[r++];
}

for (k = 0; k < size; k++)
{
    nums[k + low] = sorted[k];
}

return count;
}

long long int mergeSort(vector<long long> &nums, long long low, long long high)
{
    long long inv_count = 0;
    if (low >= high)
        return 0;
    int mid = low + (high - low) / 2;
    inv_count += mergeSort(nums, low, mid);
    inv_count += mergeSort(nums, mid + 1, high);
    inv_count += merge(nums, low, mid, high);

    return inv_count;
}
long long int inversionCount(long long arr[], long long N)
{
    vector<long long> nums;
    for (int i = 0; i < N; i++)
        nums.push_back(arr[i]);

    return mergeSort(nums, 0, N - 1);
}
};
