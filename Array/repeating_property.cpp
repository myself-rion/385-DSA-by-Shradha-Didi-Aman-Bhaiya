int findDuplicate(vector<int> &nums)
{
    // cyclic sort
    while (nums[0] != nums[nums[0]])
    {
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}