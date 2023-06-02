class Solution {
public:
    void f(vector<vector<int>>& adj, vector<int>& visited, int src, int& ans) {
        visited[src] = 1;
        ans++;
        
        for(auto it : adj[src]) {
            if(!visited[it]) {
                f(adj, visited, it, ans);
            }
        }
        
        return;
    }
    int dfs(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> visited(n+1, 0);
        int count = 0;
        f(adj, visited, src, count);
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        vector<vector<int>> adj(n + 10);
        
        for(int i = 0; i < n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            
            double r = (double)bombs[i][2];
            
            for(int j = 0; j < n; j++){
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                
                double dist = sqrt((double)((double)((double)(x2-x1)*(double)(x2-x1)) + (double)((double)(y2-y1)*(double)(y2-y1))));
                
                if(dist <= r) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            ans = max(ans, dfs(adj, i));
        }
        
        return ans;
    }
};