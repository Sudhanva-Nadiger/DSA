class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, ans = 0, index = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for(auto it : nums) {
            sum += (it ? 1 : -1);
            
            if(mp.find(sum) != mp.end()) {
                ans = max(ans, index-mp[sum]);
            } else {
                mp[sum] = index;
            }
            
            index++;
        }
        
        return ans;
    }
};