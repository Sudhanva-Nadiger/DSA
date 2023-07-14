class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<int> indeg(n);
        vector<vector<int>> adj(n);
        
        for(auto it : edges) {
            indeg[it[0]]++;
            indeg[it[1]]++;
            
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 1) {
                q.push(i);
            }
        }
        vector<int> ans;
        
        while(q.size()) {
            ans.clear();
            
            int k = q.size();
            while(k--) {
                int node = q.front();
                q.pop();
                
                ans.push_back(node);
                
                for(auto it : adj[node]) {
                    indeg[it]--;
                    if(indeg[it] == 1) {
                        q.push(it);
                    }
                }
            }
        }
        
        return ans;
    }
};