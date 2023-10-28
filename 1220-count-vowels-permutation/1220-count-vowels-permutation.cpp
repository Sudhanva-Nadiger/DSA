class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9+7;
    int solve(unordered_map<int,vector<int>>& adj,int n,int node){
        if(n == 0){
            return 1;
        }
        if(dp[n][node] != -1){
            return dp[n][node];
        }
        int ans = 0;
        for(int it : adj[node]){
            ans = (ans+solve(adj,n-1,it))%mod;
        }
        
        return dp[n][node] = ans;
    }
    
    int countVowelPermutation(int n) {
        if(n == 1){
            return 5;
        }
        
        unordered_map<char,int> d;
        d['a'] = 1;
        d['e'] = 2;
        d['i'] = 3;
        d['o'] = 4;
        d['u'] = 5;
        
        unordered_map<int,vector<int>> adj;
        
        adj[d['a']].push_back(d['e']);
        adj[d['e']].push_back(d['a']);
        adj[d['e']].push_back(d['i']);
        adj[d['i']].push_back(d['a']);
        adj[d['i']].push_back(d['e']);
        adj[d['i']].push_back(d['o']);
        adj[d['i']].push_back(d['u']);
        adj[d['o']].push_back(d['i']);
        adj[d['o']].push_back(d['u']);
        adj[d['u']].push_back(d['a']);
        dp = vector<vector<int>>(n,vector<int>(6,-1));
        int ans = 0;
        for(int i = 1;i<=5;i++){
            ans = (ans+solve(adj,n-1,i))%mod;
        }
        return ans%mod;
    }
};