class Solution {
public:
    int dp[100001][2];
    int f(string& s, int i, bool inA) {
        if(i >= s.size()) {
            return 0;
        }
        
        int& st = dp[i][inA];
        
        if(st != -1) {
            return st;
        }
        
        int ans = 1e9;
        
        if(inA) {
            if(s[i] == 'b') {
               // delete it or startB
                int del = 1+f(s, i+1, inA);
                
                int startB = f(s, i+1, !inA);
                
                return st = min(del, startB);
            }
            
            return st = f(s, i+1, inA);
        }
        
        if(s[i] =='a') {
            return st = 1+f(s, i+1, inA);
        }
        
        return st = f(s, i+1, inA);
    }
    int minimumDeletions(string s) {
        
        memset(dp, -1, sizeof(dp));
        return f(s, 0, true);
    }
};