class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cs = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            cs += nums[i];
            
            int re = cs%k;
            
            if(re < 0) {
               re += k; 
            }
            
            if(mp.find(re) != mp.end()) {
                ans += mp[re];
            }
            
            mp[re]++;
        }
        return ans;
    }
};