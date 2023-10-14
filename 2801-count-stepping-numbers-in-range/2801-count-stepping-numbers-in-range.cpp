class Solution {
public:
    long long mod = 1e9 + 7;
    long long dp[101][11][2][2];
    long long f(string& nums, long long i, long long prev, long long tight, long long isLeading) {
        if(i == nums.size()) {
            return (long long)!isLeading;
        }
        
        long long& st = dp[i][prev+1][tight][isLeading];
        if(st != -1) return st;
        
        int ub = (tight ? nums[i]-'0' : 9);
        
        long long ans = 0ll;
        for(long long dig = 0; dig <= ub; dig++) {
            if(isLeading || abs(prev-dig) == 1) {
                ans = (ans + f(nums, i+1, dig, tight&&(dig == ub), isLeading&&(dig == 0)))%mod;
            }
        }
        
        return st = ans%mod;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof dp);
        long long ans = f(high, 0, -1, 1, 1)%mod;
        memset(dp, -1, sizeof dp);
        ans -= f(low, 0, -1, 1, 1)%mod;
        if(ans < 0) ans += mod;
        int i = 1;
        for(; i < low.size(); i++) {
            if(abs(low[i]-low[i-1]) != 1) {
                break;
            }
        }
        ans += (i == low.size());
        return ans%mod;
    }
};