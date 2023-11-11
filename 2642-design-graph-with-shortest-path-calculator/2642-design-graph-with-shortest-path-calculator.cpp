class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int n;
    
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        auto it = edge;
        adj[it[0]].push_back({it[1], it[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[node1] = 0;
        pq.push({0, node1});
        
        while(pq.size()) {
            auto [wt, node]  = pq.top();
            pq.pop();
            
            if(wt > dist[node]) {
                continue;
            }
        
            for(auto [v, w] : adj[node]) {
                if(dist[v] > wt + w) {
                    dist[v] = wt + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[node2] == 1e9 ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */