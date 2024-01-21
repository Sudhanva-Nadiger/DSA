class Solution {
public:
    bool okay(vector<int>& nums, int lim, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= lim) {
                count++;
                i++;
            }
        }
        
        return count >= k;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int ans = 0, mini = 1e9+1, maxi = -1e9;
        for(auto it : nums) {
            mini = min(mini, it);
            maxi = max(maxi, it);
        }
        
        while(mini <= maxi) {
            int mid = (mini + maxi)/2;
            if(okay(nums, mid, k)) {
                ans = mid;
                maxi = mid-1;
            } else {
                mini = mid+1;
            }
        }
        
        return ans;
    }
};