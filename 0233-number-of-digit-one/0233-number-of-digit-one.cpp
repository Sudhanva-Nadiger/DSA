class Solution {
public:
    int dp[20][20][3];
    int f(string& num, int i, int count, bool tight) {
        if(i == num.size()) {
            return count;
        }
        
        int& st = dp[i][count][tight];
        if(st != -1) return st;
        
        int ub = tight ? (num[i]-'0') : 9;
        
        
        int ans = 0;
        for(int digit = 0; digit <= ub; digit++) {
            ans += f(num, i+1, count + (digit == 1), tight && (digit == ub));
        }
        
        return st = ans;
    }
    int countDigitOne(int n) {
        memset(dp, -1, sizeof dp);
        string s = to_string(n);
        return f(s, 0, 0, true);
    }
};