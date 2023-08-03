class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0) return;
        int n= nums.size();
        
        k= k%n; //when k> size of the array, this is the effective number of rotations

        reverse(nums.begin(), nums.end()); // reverses the whole array
        reverse(nums.begin(),nums.begin()+k); // reverses first k number of elements
        reverse(nums.begin()+k,nums.end()); // reverses rest of the elements
    }
};