class Solution {
public:
    int dp[12][2][2][(int)(1<<11)];
    int f(string& num, int i, int tight, int isLeading, int mask) {
        if(i == num.size()) {
            return !isLeading;
        }
        
        int& st = dp[i][tight][isLeading][mask];
        if(st != -1) return st;
        
        int ans = 0;
        int ub = tight ? num[i]-'0' : 9;
        
        for(int dig = 0; dig <= ub; dig++) {
            if(mask&(1<<dig)) continue;
            
            int m = (isLeading && !dig) ? mask : (mask | (1<<dig));
            ans += f(num, i+1, tight&&(dig==ub), isLeading&&(!dig), m);
        }
        
        return st = ans;
    }
    
    int countSpecialNumbers(int n) {
        memset(dp, -1, sizeof dp);
        string s = to_string(n);
        return f(s, 0, 1, 1, 0);
    }
};