class Solution {
public:
    void generateMatrix(vector<vector<int>>& edges, vector<vector<int>>& adj) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
    }
    
    vector<int> topologicalSort(int k, vector<vector<int>>& adj) {
        vector<int> ans;
        vector<int> indegree(adj.size());
        
        for(int i = 1; i <= k; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 1; i <= k; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(q.size()) {
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto it : adj[front]) {
                indegree[it]--;
                
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adj1(k+1), adj2(k+1);
        generateMatrix(rowConditions, adj1);
        generateMatrix(colConditions, adj2);
        
        vector<int> arr1 = topologicalSort(k, adj1);
        vector<int> arr2 = topologicalSort(k, adj2);
        
        if(arr1.size() != k || arr2.size() != k) {
            return {};    
        }
        
        map<int, pair<int, int>> mp;
        
        for(int i = 0; i < k; i++) {
            mp[arr1[i]].first = i;
            mp[arr2[i]].second = i;
        }
        
        vector<vector<int>> ans(k, vector<int>(k));
        
        for(auto it : mp) {
            int num = it.first;
            auto [row, col] = it.second;
            
            ans[row][col] = num;
        }
        return ans;
    }
};