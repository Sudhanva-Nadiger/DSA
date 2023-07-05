class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            int mid = (l+r)/2;
            
            int num;
            if((nums[mid] < nums[0]) == (target < nums[0])) {
                // if nums[mid] and target on the same sorted section
                num = nums[mid];
            }else {
                if(nums[mid] < nums[0]) {
                    num = 1e9; 
                }else {
                    num = -1e9;
                }
            }
            
            if(num > target) {
                r = mid-1;
            }else if(num < target) {
                l = mid+1;
            }else {
                return mid;
            }
        }
        
        return -1;
    }
};