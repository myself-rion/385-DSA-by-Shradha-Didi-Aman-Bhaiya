vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{

    vector<vector<int>> ans;

    if (intervals.size() == 0) return ans;

    sort(intervals.begin(), intervals.end()); //sort to get consecutive intervals

    vector<int> tempInterval = intervals[0]; //to store mergeable intervals

    for (auto &it : intervals)
    {
        if (it[0] <= tempInterval[1]) //cond: {1,3},{2,4} if start of interval is <= previous interval's end then merging is possible
        {
            tempInterval[1] = max(tempInterval[1], it[1]); //max(3,4)
        }
        else //no interval to merge
        {
            ans.push_back(tempInterval);
            tempInterval = it; //setting new pair to compare
        }
    }

    ans.push_back(tempInterval); //inserting last interval is stored in tempInterval

    return ans;
}