class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        
        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, -1e5);
        
        pq.push({1.0, start_node});
        dist[start_node] = 1.0;
        
        while(pq.size()) {
            auto [prob, node] = pq.top();
            pq.pop();
            
            if(dist[node] > prob) continue;
            
            for(auto [child, wt] : adj[node]) {
                if(wt*prob > dist[child]) {
                    dist[child] = wt*prob;
                    pq.push({dist[child], child});
                }
            }
        }
        
        return max(0.0, dist[end_node]);
    }
};