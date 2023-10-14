class Solution {
public:
    int mod = 1e9 + 7;
    int dp[25][2][2][401];
    int f(string& nums, int i, int tight, int isLeading, int sum, int mini, int maxi) {
        if(sum > maxi) {
            return 0;    
        }
        
        if(i == nums.size()) {
            return (mini <= sum && sum <= maxi);
        }
        
        int& st = dp[i][tight][isLeading][sum];
        if(st != -1) return st;
        
        int ub = (tight ? nums[i]-'0' : 9);
        
        int ans = 0;
        for(int dig = 0; dig <= ub; dig++) {
            ans = (ans + f(nums, i+1, tight&(dig == ub), isLeading&(!dig), sum + dig, mini, maxi))%mod;
        }
        
        return st = ans%mod;
    }
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof dp);
        int ans = f(num2, 0, 1, 1, 0, min_sum, max_sum);
        memset(dp, -1, sizeof dp);
        ans = (ans - f(num1, 0, 1, 1, 0, min_sum, max_sum) + mod)%mod;
        int sum = 0;
        for(auto it : num1) sum += (it-'0');
        if(min_sum <= sum && sum <= max_sum) {
            ans++;
        }
        return ans%mod;
    }
};