// Using Array Preprocessing
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left; // finding max height left to right array
        vector<int>right; // finding max height right to left array
        int size = height.size();
        int temp1= height[0];
        int temp2= height[size-1];
        int result=0;
        for(int i=0; i< size; i++)
        {
            if(height[i]> temp1){
                temp1=height[i];
            }
            left.push_back(temp1);
        }
        for(int j=size-1;j>=0;j--)
        {
            if(height[j]> temp2){
                temp2=height[j];
            }
            
            right.push_back(temp2);
        }
        reverse(right.begin(),right.end()); // reversing for right to left array
        for(int k=0; k<size; k++)
        {
            result+= min(left[k],right[k])- height[k];
        }
        return result;
    }
};