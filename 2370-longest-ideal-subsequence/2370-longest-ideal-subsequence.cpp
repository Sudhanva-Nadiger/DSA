class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s,int i,int k,int prev){
        if(i >= s.size()){
            return 0;
        }
        
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }
        int in = 0;
        if(prev == -1 or abs((s[i]-'a')-prev) <= k){
            in = 1+solve(s,i+1,k,s[i]-'a');
        }
        int ex = solve(s,i+1,k,prev);
        
        return dp[i][prev+1] = max(in,ex);
        
    }

    int longestIdealString(string s, int k) {
        dp = vector<vector<int>>(s.size()+1,vector<int>(27,-1));
        return solve(s,0,k,-1);
    }
};