class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100][201];
    int f(vector<int>& nums, int start, int end, int fuel) {
        if(fuel < 0) {
            return 0;
        }
        
        int& st = dp[start][fuel];
        
        if(st != -1) return st;
        
        int ans =(start ==end);
        for(int i = 0; i < nums.size(); i++) {
            ans %= mod;
            if(start != i)
                ans += f(nums, i, end, fuel-abs(nums[start]-nums[i]))%mod;
        }
        
        return st = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return f(locations, start, finish, fuel);
    }
};