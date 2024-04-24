using ll = long long;
using pll = pair<ll, ll>;

class Solution {
public:
    ll inf = INT_MAX;
    
    vector<vector<ll>> dist;
    
    void dj(vector<vector<pll>>& adj, int src) {
        
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, src});
        dist[src][src] = 0;
        
        while(pq.size()) {
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(wt > dist[src][node]) {
                continue;
            }
            
            for(auto [child, w] : adj[node]) {
                if(w + wt < dist[src][child]) {
                    dist[src][child] = w + wt;
                    pq.push({dist[src][child], child});
                }
            }
        }
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        dist = vector<vector<ll>>(26, vector<ll>(26, inf));
        
        vector<vector<pll>> adj(26);
        int n = original.size();
        
        for(int i = 0; i < n; i++) {
            ll u = original[i] - 'a';
            ll v = changed[i] - 'a';
            ll w = cost[i];
            
            adj[u].push_back({v, w});
        }
        
        for(int i = 0; i < 26; i++) {
            dj(adj, i);
        }
        
        int m = source.size();
        ll ans = 0;
        for(int i = 0; i < m; i++) {
            if(source[i] != target[i]) {
                int u = source[i] - 'a';
                int v =target[i] - 'a';
                
                if(dist[u][v] == inf) {
                    return -1;
                }
                
                ans += dist[u][v];
            }
        }
        
        return ans;
    }
};