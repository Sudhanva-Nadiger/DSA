class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool solve(string& s1,string&s2,string& s3,int i,int j,int k){
        if(i>=s1.size() and j>= s2.size() and k>=s3.size()){
            return true;
        }
        if(i>=s1.size() and j>=s2.size() and k<s3.size()){
            return false;
        }
        
        if(i>=s1.size() and j<s2.size() and k<s3.size()){
            return s2.substr(j) == s3.substr(k);
        }
        
        if(j>=s2.size() and i<s1.size() and k<s3.size()){
            return s1.substr(i) == s3.substr(k);
        }
        
        if(k>=s3.size() and (i<s1.size() or j<s2.size())){
            return false;
        }
        
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        
        if(s1[i] == s3[k] and s2[j] == s3[k]){
            return dp[i][j][k] = solve(s1,s2,s3,i+1,j,k+1) or solve(s1,s2,s3,i,j+1,k+1);
        }
        
        if(s1[i] == s3[k]){
            return dp[i][j][k] = solve(s1,s2,s3,i+1,j,k+1);
        }
        if(s2[j] == s3[k]){
            return dp[i][j][k]= solve(s1,s2,s3,i,j+1,k+1);
        }
        
        return dp[i][j][k] = false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int o = s3.size();
        dp = vector<vector<vector<int>>> (m+1,vector<vector<int>>(n+1,vector<int>(o+1,-1)));
        return solve(s1,s2,s3,0,0,0);
    }
};