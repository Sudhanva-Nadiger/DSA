class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int, int>> adj[n];
        for(auto e: edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(n, -1);
        queue<pair<int, int>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        
        while(pq.size()) {
            auto [time, node] = pq.front();
            pq.pop();
            
            if(time > dist[node]) continue;
            
            for(auto& [child, wt] : adj[node]) {
                
                if(wt + time < dist[child] || dist[child] == -1) {
                    int newTime = wt + time;
                    if(newTime >= disappear[child]) {
                        continue;
                    } else {
                        dist[child] = time + wt;
                        pq.push({dist[child], child});
                    }
                }
            }
        }
        
        return dist;
    }
};