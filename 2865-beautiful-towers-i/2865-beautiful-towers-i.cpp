class Solution {
public:
    #define ll long long
    
    ll f(vector<int>& nums, int index) {
        ll ans = nums[index];
        ll maxi = nums[index];
        
        for(int i = index+1; i < nums.size(); i++) {
            ll next = min(maxi, (ll)nums[i]);
            ans += next;
            
            maxi = next;
        }
        
        maxi = nums[index];
        
        for(int i = index-1; i >= 0; i--) {
            ll next = min(maxi, (ll)nums[i]);
            
            ans += next;
            maxi = next;
        }
        
        return ans;
    }
    
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll ans = 0ll;
        for(int i = 0; i < maxHeights.size(); i++) {
            ans = max(ans, f(maxHeights, i));
        }
        return ans;
    }
};