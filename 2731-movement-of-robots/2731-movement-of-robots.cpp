class Solution {
public:
    int sumDistance(vector<int>& numss, string s, int d) {
        int n = numss.size(), mod = 1e9 + 7; long long ans = 0;
        vector<long long> nums(numss.begin(), numss.end());
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'R') {
                nums[i] += d;
            } else {
                nums[i] -= d;
            }
            
        }
        
        sort(nums.begin(), nums.end());
        auto arr = nums;
        for(int i = 1; i < n; i++) nums[i] += nums[i-1];
        
        for(int i = 0; i < n; i++) {
            int l = i;
            auto lSum = (i > 0 ? nums[i-1] : 0);
            ans = (ans + l*arr[i]-lSum)%mod;
        }
        
        return ans;
        
    }
};