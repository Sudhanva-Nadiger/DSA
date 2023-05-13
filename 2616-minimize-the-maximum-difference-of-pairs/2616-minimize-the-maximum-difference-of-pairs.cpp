class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int l = 0;
        int r = nums[n-1] - nums[0];
        
        int ans = 0;
        
        while(l <= r) {
            int mid = (l+r)/2;
            int k = 0;
            for(int i = 1; i < n and k < p; i++) {
                if(nums[i]- nums[i-1] <= mid) {
                    k++;
                    i++;
                }
            }
            
            if(k >= p) {
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        
        return ans;
        
    }
};