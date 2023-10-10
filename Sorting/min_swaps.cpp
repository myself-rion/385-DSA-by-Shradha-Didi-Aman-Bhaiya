// Intuition: Sort all of them & check how many swaps does it take to revert it back

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        int swaps = 0;
        vector<pair<int, int>> store; //to store value index pair

        for (int i = 0; i < nums.size(); i++)
        {
            store.push_back({nums[i], i}); //{value, index}
        }

        sort(store.begin(), store.end());

        for (int i = 0; i < nums.size(); i++)
        {

            int value = store[i].first;
            int index = store[i].second;

            if (index != i) //not at its previous position
            {
                swaps++;
                swap(store[i], store[index]);
                i--; //to keep the pointer at the element till it gets back to its previous position
            }
        }

        return swaps;
    }
};