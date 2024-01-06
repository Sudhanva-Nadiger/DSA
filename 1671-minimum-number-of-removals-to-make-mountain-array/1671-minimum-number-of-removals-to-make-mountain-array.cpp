class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1), suff(n, 1);
        
        for(int i = 1; i < n; i++) {
            
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    pref[i] = max(pref[i], pref[j]+1);
                }
            }
            
            int k = n-i-1;
            
            for(int l = n-1; l > k; l--) {
                if(nums[k] > nums[l]) {
                    suff[k] = max(suff[k], suff[l]+1);
                }
            }
        }
        
        int ans = n+1;
        
        for(int i = 1; i < n-1; i++) {
            if(pref[i] == 1 || suff[i] == 1) continue;
            int len = pref[i] + suff[i] - 1;
            ans = min(ans, n-len);
        }
        
        return ans;
    }
};