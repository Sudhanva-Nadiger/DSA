class Solution {
public:
    
    bool checkIsComplete(vector<int>& nodes, vector<int>& indegree) {
        for(auto it : nodes) {
            if(indegree[it] != nodes.size()-1) {
                return false;
            }
        }
        
        return true;
    }
    
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& include) {
        visited[node] = 1;
        include.push_back(node);
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(it, adj, visited, include);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), visited(n, 0);
        
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                vector<int> nodesInComponent;
                dfs(i, adj, visited, nodesInComponent);
                ans += checkIsComplete(nodesInComponent, indegree);
            }
        }
        
        return ans;
    }
};