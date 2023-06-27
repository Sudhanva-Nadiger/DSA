class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            for(auto e : graph[i]) {
                adj[e].push_back(i);
            }
        }
        
        
        vector<int> indegree(n);
        
        for(auto it : adj) {
            for(auto e : it) {
                indegree[e]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(q.size()) {
            auto front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto it : adj[front]) {
                indegree[it]--;
                
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};