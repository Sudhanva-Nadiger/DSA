class Solution {
public:
    int dfs(unordered_map<int, vector<int>>& adj, int node, vector<int>& info) {
        int ans = 0;
        
        for(auto it : adj[node]) {
            int time = info[node] + dfs(adj, it, info);
            ans = max(ans,time);
        }
        
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        
        return dfs(adj, headID, informTime);
    }
};