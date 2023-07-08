//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfs(vector<vector<int>>& adj, vector<int>& visited, stack<int>& st, int node) {
	    visited[node] = 1;
	    
	    for(auto it : adj[node]) {
	        if(!visited[it]) {
	            dfs(adj, visited, st, it);
	        }
	    }
	    
	    st.push(node);
	}
	
	void f(vector<vector<int>>& adj, vector<int>& visited, int node) {
	    visited[node] = 1;
	    
	    for(auto it : adj[node]) {
	        if(!visited[it]) {
	            f(adj, visited, it);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V);
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(adj, visited, st, i);
            }
        }
        
        vector<vector<int>> g(V);
        for(int i = 0;i < V; i++) {
            visited[i] = 0;
            for(auto it : adj[i]) {
                g[it].push_back(i);
            }
        }
        int ans = 0;
        while(st.size()) {
            int t = st.top();
            st.pop();
            
            if(!visited[t]) {
                ans++;
                f(g, visited, t);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends