class Solution {
public:
    int dp[101][3];
    int f(string& s, int i, int taken) {
        if(i > s.size()) return 0;
        
        if(taken){
            int num2 = s[i-1]-'0';
            if(taken == 1){
                if(num2 == 0){
                    return 0;
                }
            }
            if(taken == 2){
                int num1 = s[i-2]-'0';
                int num = num1*10 + num2;
                if(num > 26 or num < 10){
                    return 0;
                }
            }
        }
        
        if(dp[i][taken] != -1) {
            return dp[i][taken];
        }
        
        if(i == s.size()) {
            return 1;
        }
        
        int one = f(s, i+1, 1);
        int two = f(s, i+2, 2);
        
        return dp[i][taken] = one+two;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return f(s, 0, 0);
    }
};