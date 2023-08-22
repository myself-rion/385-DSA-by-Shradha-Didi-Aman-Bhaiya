vector<int> findDuplicates(vector<int> &nums)
{
    if (nums.size() == 1)
        return {};
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        nums[(nums[i] - 1) % n] = nums[(nums[i] - 1) % n] + n; // incrementing values corresponding indexes by N
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 2 * n)
            ans.push_back(i + 1); // only repeated numbers corresponding indexes will consist twice of N
    }

    return ans;
}