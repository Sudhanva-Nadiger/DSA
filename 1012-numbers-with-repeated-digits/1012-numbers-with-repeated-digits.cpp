class Solution {
public:
    int dp[20][2][2][(int)(1<<11)][2];
    int f(string& num, int i, int tight, int isLeading, int mask, bool ok) {
        if(i == num.size()) {
            return (!isLeading && ok);
        }
        
        int& st = dp[i][tight][isLeading][mask][ok];
        if(st != -1) return st;
        
        int ans = 0;
        int ub = tight ? num[i]-'0' : 9;
        
        for(int dig = 0; dig <= ub; dig++) {
            if(mask&(1<<dig)) {
                ans += f(num, i+1, tight&(dig==ub),isLeading&(!dig), mask, true);
            } else {
                int m = (isLeading && dig == 0) ? mask : (mask | (1<<dig));
                ans += f(num, i+1, tight&(dig==ub),isLeading&(!dig), m, ok);
            }
        }
        
        return st = ans;
    }
    
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof dp);
        string num = to_string(n);
        return f(num, 0, 1, 1, 0, 0);
    }
};