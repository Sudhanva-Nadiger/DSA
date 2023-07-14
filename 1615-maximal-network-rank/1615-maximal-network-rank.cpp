class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n));
        vector<int> indeg(n);
        
        for(auto it : roads) {
            adj[it[0]][it[1]] = 1;
            adj[it[1]][it[0]] = 1;
            indeg[it[0]]++;
            indeg[it[1]]++;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int a = indeg[i];
                int b = indeg[j];
                int tot = a + b;
                if(adj[i][j]) {
                    tot -= 1;
                }
                
                ans = max(ans, tot);
            }
        }
        
        return ans;
    }
};