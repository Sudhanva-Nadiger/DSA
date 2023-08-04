class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100001][3][5];
    
    int f(int n, int absentCount, int prevLate) {
        if(absentCount > 1 || prevLate >= 3) return 0;
        
        if(n == 0) return 1;
        
        if(dp[n][absentCount][prevLate] != -1)
            return dp[n][absentCount][prevLate];
        
        int p = f(n-1, absentCount, 0);
        int l = f(n-1, absentCount, prevLate+1);
        int a = f(n-1, absentCount+1, 0);
        
        return dp[n][absentCount][prevLate] = ((p+l)%mod + a)%mod;
    }
    
    int checkRecord(int n) {
        memset(dp, -1, sizeof dp);
        return f(n, 0, 0);
    }
};