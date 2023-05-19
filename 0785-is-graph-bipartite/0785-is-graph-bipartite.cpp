class Solution {
public:
    bool f(int node, vector<vector<int>>& adj, vector<int>& colorArr, int color) {
        colorArr[node] = color;
        
        for(auto it : adj[node]) {
            if(colorArr[it] == -1) {
                bool isBipartite = f(it, adj, colorArr, color^1);
                if(!isBipartite) {
                    return false;
                }
            }else if(colorArr[it] == color) {
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorArr(n, -1);
        for(int i = 0; i < n; i++) {
            if(colorArr[i] == -1) {
                if(!f(i, graph, colorArr, 0)){
                    return false;
                }
            }
        }
        return true;
    }
};