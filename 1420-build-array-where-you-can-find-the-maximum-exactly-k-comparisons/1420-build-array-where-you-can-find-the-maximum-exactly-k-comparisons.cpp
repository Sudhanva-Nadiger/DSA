class Solution {
public:
    int mod = 1e9 + 7;
    int dp[55][55][102];
    int f(int n, int m, int k, int index, int maxVal) {
        if(index == n) {
            return (k == 0);
        }
        
        if(k < 0) {
            return 0;
        }
        
        int& st = dp[k][index][maxVal+1];
        
        if(st != -1) return st;
        
        int ans = 0;
        
        for(int i = 1; i <= m; i++) {
            if(i > maxVal) {
                ans = (ans + f(n, m, k-1, index+1, i))%mod;        
            } else {
                ans = (ans + f(n, m, k, index+1, maxVal))%mod;
            }
        }
        
        return st = ans%mod;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof dp);
        return f(n, m, k, 0, -1);
    }
};