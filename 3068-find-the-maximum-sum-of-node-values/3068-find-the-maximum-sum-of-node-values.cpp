class Solution {
public:
    #define ll long long
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans = 0, count = 0, minChange = INT_MAX, totalChange = 0;;
        for(auto it : nums) {
            ll change = (it^k)-it;
            
            if(change >= 0) {
                totalChange += change;
                count++;
            }
            
            ans += it;
            change = abs(change);
            minChange = min(minChange, change);
        }
        
        if(count&1) {
            totalChange = max(0ll, totalChange-minChange);
        }
        
        return ans + totalChange;
    }
};