
class Solution {
public:
    typedef pair<long long, long long> pii;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long int> dist(n+1, 1e15);
        vector<int> count(n+1, 0);
        vector<vector<pair<int,long long>>> adj(n);
        
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], (long long)it[2]});
            adj[it[1]].push_back({it[0], (long long)it[2]});
        }
        
        int mod = 1e9+7;
        
        dist[0] = 0;
        count[0] = 1;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        
        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            
            int node = top.second;
            long long d = top.first;
            
            for(auto it : adj[node]) {
                if(dist[it.first] > it.second + d) {
                    dist[it.first] = it.second + d;
                    pq.push({dist[it.first], it.first});
                    count[it.first] = count[node];
                }else if(dist[it.first] == it.second + d) {
                    count[it.first] = (count[it.first]%mod + count[node]%mod)%mod;
                }
            }
        }
        
        return count[n-1]%mod;
    }
};