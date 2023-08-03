//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
    {
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        vector<pair<int,int>> adj[n];
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int d=edge[2];
            
            adj[u].push_back({v,d});
        }
        vector<int> indeg(n,0);
        for(int i=0; i<n; i++)
        {
            for(auto e:adj[i])
            {
                indeg[e.first]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it: adj[node])
            {
                if(dist[node]!=INT_MAX)
                    dist[it.first]=min(dist[it.first], dist[node]+it.second);
                indeg[it.first]--;
                if(indeg[it.first]==0)
                    q.push(it.first);
            }
        }
        for(int i=0; i<n; i++)
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends