class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int maxi = 0;
        for(auto it : nums) {
            mp[it]++;
            maxi = max(maxi, mp[it]);
        }
        int ans = 0;
        for(auto it : mp) {
            if(it.second == maxi) {
                ans += maxi;
            }
        }
        
        return ans;
    }
};