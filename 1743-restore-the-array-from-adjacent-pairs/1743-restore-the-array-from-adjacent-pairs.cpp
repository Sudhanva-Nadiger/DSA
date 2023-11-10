class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& e) {
        int n = e.size()+1;
        unordered_map<int,int> mp;
        unordered_map<int,vector<int>> adj;
        for(vector<int>& v : e){
            mp[v[0]]++;
            mp[v[1]]++;
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        queue<int> q;
        int last = -1;
        for(auto it : mp){
            if(it.second == 1 and q.size() == 0){
                q.push(it.first);
            }
            else if(it.second == 1){
                last = it.first;
                break;
            }
        }
        vector<int> ans;
        while(q.size()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it : adj[curr]){
                mp[it]--;
                if(mp[it] == 1){
                    q.push(it);
                }
            }
        }
        if(ans.size() != n){
            ans.push_back(last);
        }
        return ans;
        
    }
};