class Solution {
public:
    int dp[100001][14];
    int k = 0;
    int f(unordered_map<int, vector<int>>& adj, vector<int>& coins, int node, int par, int count) {
        if(count == 14) return 0;
        
        int& st = dp[node][count];
        if(st != -1) return st;
        
        int coin = (coins[node]>>count);
        
        int a = coin - k;
        int b = (coin>>1);
        

        for(int v: adj[node]) {
            if(v != par) {
                a = a + f(adj, coins, v, node, count);
                b = b + f(adj, coins, v, node, count+1);
            }
        }
        
        return st = max(a, b);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        this->k = k;
        unordered_map<int, vector<int>> adj;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        memset(dp, -1, sizeof dp);
        return f(adj, coins, 0, -1, 0);
    }
};