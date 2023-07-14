class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        
        for(auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        
        vector<vector<int>> dp(numCourses, vector<int>(numCourses));
        
        while(q.size()) {
            int k = q.size();
            
            while(k--) {
                int node = q.front();
                q.pop();
             
                for(auto it : adj[node]) {
                    dp[node][it] = 1;
                    for(int i = 0; i < numCourses; i++) {
                        if(dp[i][node]) {
                            dp[i][it] = 1;
                        }
                    }
                    
                    indeg[it]--;
                    if(indeg[it] == 0) {
                        q.push(it);
                    }
                }
            }
        }
        
        vector<bool> ans;
        for(auto it : queries) {
            ans.push_back(dp[it[0]][it[1]]);
        }
        return ans;
    }
};