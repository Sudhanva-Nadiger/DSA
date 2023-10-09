class Solution {
public:
    int first(vector<int>& nums, int target){
        int i = 0;
        int j = nums.size()-1;
        int res = -1;
        while(i<=j){
            int mid = (i+j)/2;
            
            if(nums[mid]>target){
                j = mid-1;
            }
            else if(nums[mid]<target)
            {
                i = mid+1;
            }
            else
            {
                res = mid;
                j=mid-1;
            }
        } 
            return res;
    }
    int second(vector<int>& nums, int target){
        int i = 0;
        int j = nums.size()-1;
        int res = -1;
        while(i<=j){
            int mid = (i+j)/2;
            
            if(nums[mid]>target){
                j = mid-1;
            }
            else if(nums[mid]<target)
            {
                i = mid+1;
            }
            else{
                res = mid;
                i = mid+1;
            }
        }
        
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),second(nums,target)};    
        
    }
};