class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       int i = 0,j = nums.size()-1;
        
        while(i<j){
            int right = nums[i]%2;
            int left = nums[j]%2;
            
            if(!right){
                i++;
            }
            if(left){
                j--;
            }
            if(right==1){
                swap(nums[i],nums[j]);
            }
            else if(!left){
                swap(nums[i],nums[j]);
            }
        }
        
        return nums;
    }
};