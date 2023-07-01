class Solution {
public:
    using p = pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<p, vector<p>, greater<p>> pq;
        
        pq.push({0, k});
        dist[k] = 0;

        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            
            int node = top.second;
            int wt = top.first;
            
            for(auto it : adj[node]) {
                if(dist[it.first] > wt + it.second) {
                    dist[it.first] = wt + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        
        int ans = *max_element(begin(dist)+1, end(dist));
        return ans == 1e9 ? -1 : ans;
    }
};