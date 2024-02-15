class Solution {
public:
    #define ll long long
    
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<ll> pref(n);
        
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = (ll)nums[i] + pref[i-1];
        }
        
        
        for(int i = n-1; i > 1; i--) {
            if(nums[i] < pref[i-1]) {
                return pref[i];
            }
        }
        
        return -1;
    }
};