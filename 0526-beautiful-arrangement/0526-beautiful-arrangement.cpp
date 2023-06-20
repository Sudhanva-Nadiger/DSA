class Solution {
public:
    int dp[(int)(1<<20)][16];
    int f(int n, int mask, int index) {
        if(index == n+1) {
            return 1;
        }
        if(dp[mask][index] != -1) return dp[mask][index];
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++) {
            if(mask&(1<<i)) {
                continue;
            }else {
                if(i%index == 0 || index%i == 0) {
                    ans += f(n, mask | (1 << i), index+1);
                }
            }
        }
        
        return dp[mask][index] = ans;
    }
    
    int countArrangement(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n, 0, 1);
    }
};