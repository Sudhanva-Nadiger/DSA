class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        unordered_set<int> visited;
        vector<double> dist(n+1, 0.0);
        dist[start] = 1.0;
        
        priority_queue<pair<double, int>> q;
        
        q.push({1.0, start});
        // visited.insert(start);
        double ans = 0.0;
        
        while(q.size()) {
            auto front = q.top();
            q.pop();
            int node = front.second;
            double prob = front.first;
            
            if(!visited.count(node)) {
                visited.insert(node);
                
                for(auto it : adj[node]) {
                    if(dist[it.first] < prob*it.second) {
                        dist[it.first] = prob*it.second;
                        q.push({dist[it.first], it.first});
                    }
                }
            }
        }
        
        return dist[end];
    }
};