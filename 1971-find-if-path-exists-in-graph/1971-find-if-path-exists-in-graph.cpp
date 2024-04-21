class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int src,int dest,vector<int>& visited){
        if(src == dest){
            return true;
        }
        
        visited[src] =1;
        
        for(auto it : adj[src]){
            if(!visited[it]){
                bool found = dfs(adj,it,dest,visited);
                if(found){
                    return true;
                }
            }
        }
        
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n);
        return dfs(adj,source,destination,visited);
    }
};