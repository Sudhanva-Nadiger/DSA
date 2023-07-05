class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 1e9;
        int ans = 0;
        while(left <= right) {
            int mid = (left+right)>>1;
            
            int part = 1;
            int sum = 0;
            
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] > mid) {
                    part = k+1;
                    break;
                }
                
                if(nums[i]+sum <= mid) {
                    sum += nums[i];
                }else {
                    sum = nums[i];
                    part++;
                }
            }
            
            if(part <= k) {
                ans = mid;
                right =mid-1;
            }else {
                left = mid+1;
            }
        }
        
        return ans;
    }
};