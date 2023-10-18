class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        if(n == 1) return time[0];        
        if(relations.size() == 0) return *max_element(time.begin(), time.end());
        if(n == 2) return time[0] + time[1];
        
        vector<int> indegree(n+1, 0);
        vector<int> adj[n+1];
        
        int res = *max_element(time.begin(), time.end());
        for(auto it : relations) {
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        
        queue<pair<int, int>> q;
        for(int i = 1; i <= n; i++) {
            if(!indegree[i]) {
                res = max(res, time[i]);
                q.push({i, time[i-1]});
            }
        }
        map<int, int> mp;
        
        while(q.size()) {
            auto [node, t] = q.front();
            q.pop();
        
            for(auto it : adj[node]) {
                indegree[it]--;
                mp[it] = max(mp[it], t);
                
                if(indegree[it] == 0) {
                    res = max(res, time[it-1]+mp[it]);
                    q.push({it, time[it-1]+mp[it]});
                }
            }
        }
        return res;
    }
};