class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        
        vector<vector<int>> adj(n);
        
        for(auto it : edges) {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]] ++;
        }
        
        
        queue<int> q;
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(!indeg[i]) {
                q.push(i);
                count++;
            }
        }
        
        while(q.size()) {
            
            int front = q.front();
            q.pop();
            
            for(auto it : adj[front]) {
                indeg[it]--;
                
                if(!indeg[it]) {
                    q.push(it);
                    count++;
                }
            }
        }
        
        return count == n;
    }
};