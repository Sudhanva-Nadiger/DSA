class Solution {
public:
    #define ll long long
    
    ll dp[(int)1e5+3][4][3];
    ll f(string& s, int i, int count, int prev) {
        if(count == 0) return 1;
        
        if(i == s.size()) return 0;
        
        ll& st = dp[i][count][prev+1];
        
        if(st != -1) return st;
        
        ll take = 0;
        if(prev != s[i]-'0') {
            take += f(s, i+1, count-1, s[i]-'0');
        }
        
        ll notTake = f(s, i+1, count, prev);
        
        return st = take+notTake;
    }
    
    long long numberOfWays(string s) {
        memset(dp, -1, sizeof dp);
        return f(s, 0, 3, -1);
    }
};