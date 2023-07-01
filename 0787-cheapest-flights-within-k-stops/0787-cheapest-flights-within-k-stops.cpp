class Solution {
public:
    using pi = pair<int, pair<int, int>>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pi> q;
        dist[src] = 0;
        q.push({0, {src, 0}});
        
        while(q.size()) {
            auto t = q.front();
            q.pop();
             
            int stops = t.first;
            if(stops == k+1) {
                continue;
            }
            
            int node = t.second.first;
            int wt = t.second.second;
            
            for(auto it : adj[node]) {
                if(dist[it.first] > wt+it.second && stops <= k) {
                    dist[it.first] = wt + it.second;
                    q.push({stops+1, {it.first, dist[it.first]}});
                }
            }
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};