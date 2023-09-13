// intuition : fix target & match, if matched then increase the count else decrease the count
// when count is 0, means equal number of dsitinct elements till now, so update the target
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int target = 0;
        for (auto i : nums)
        {
            if (count == 0)
                target = i;

            if (target == i)
                count++;
            else
                count--;
        }

        return target;
    }
};
// in O(1) space

//majority element in an array A of size N is an element that appears more than N/2 times in the array.

class Solution{
  public:
     
    int majorityElement(int arr[], int size)
    {
        if(size==2 && arr[0]!=arr[1]) return -1;
        
        int res=0, count=1;
        for(int i=1; i<size; i++){
            if(arr[res]==arr[i]) count++;
            else count--;
            
            if(count==0){
                res=i;
                count=1;
            }
        }
        
        count=0;
        
        for(int i=0; i<size; i++){
            if(arr[i]==arr[res]) count++;
        }
        
        if(count>size/2) return arr[res];
        else return -1;
        
    }
};