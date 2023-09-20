class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = n+1;
        vector<int> pref = nums, suff = nums;
        
        if(nums[0] == x || nums[n-1] == x) ans = min(ans, 1);
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i-1];
            suff[n-i-1] += suff[n-i];
            
            if(nums[i] == x) {
                ans = min(ans, 1);
            }
            
            if(suff[n-i-1] == x || pref[i] == x) {
                ans = min(ans, i+1);
            }
        }
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[suff[i]] = i;
        }
        
        for(int i = 0; i < n; i++) {
            if(mp.find(x-pref[i]) != mp.end()) {
                int dist = i+1 + (n-mp[x-pref[i]]);
                ans = min(ans, dist);
            }
        }
        
        return ans == n+1 ? -1 : ans;
    }
};