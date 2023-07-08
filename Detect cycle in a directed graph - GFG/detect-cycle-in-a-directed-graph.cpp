//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool f(vector<int> adj[], vector<int>& visited, vector<int>& dfsCall, int node) {
        visited[node] = 1;
        dfsCall[node] = 1;
        
        for(auto it : adj[node]) {
            if(!visited[it]) {
                bool found = f(adj, visited, dfsCall, it);
                if(found) {
                    return true;
                }
            }else if(dfsCall[it]) {
                return true;
            }
        }
        
        dfsCall[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V), dfsCall(V);
        for(int i = 0; i < V; i++) {
            if(!visited[i] && f(adj, visited, dfsCall, i)) {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends