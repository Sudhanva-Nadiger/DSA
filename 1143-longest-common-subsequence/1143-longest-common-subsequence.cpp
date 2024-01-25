class Solution {
public:
    int dp[1001][1001];
    int f(string& a,string& b,int i,int j){
        if(i >= a.size() or j >= b.size()){
            return 0;
        }
        
        int& x = dp[i][j];
        if(x != -1){
            return x;
        }
        
        if(a[i] == b[j]){
            return x = 1+f(a,b,i+1,j+1);
        }
        
        return x = max(f(a,b,i+1,j),f(a,b,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return f(text1,text2,0,0);
    }
};