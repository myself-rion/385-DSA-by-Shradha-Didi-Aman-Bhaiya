// User function Template for C++

class Solution
{
public:
    bool possibleToPlace(vector<int> &stalls, int dist, int cows, int N)
    {
        int countCows = 1, coordinate = stalls[0]; //coordinate= position of cows

        for (int i = 1; i < N; i++)
        {
            if (stalls[i] - coordinate >= dist)
            {
                countCows++;
                coordinate = stalls[i];
            }
            if (countCows >= cows)
                return true;
        }

        return false;
    }

    int solve(int n, int number_of_cows, vector<int> &stalls)
    {

        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n - 1] - stalls[0]; //range of distance= max-min

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (possibleToPlace(stalls, mid, number_of_cows, n)) //checks if in this distance all the cows can be placed or not
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};