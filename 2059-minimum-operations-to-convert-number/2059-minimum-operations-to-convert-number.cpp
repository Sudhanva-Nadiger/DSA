class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int> visited(1001, 0);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = 1;
        
        while(q.size()) {
            auto [node, move] = q.front();
            q.pop();
            
            if(node == goal) return move;
            
            if(node < 0 || node > 1000) continue;
            
            for(int i = 0; i < nums.size(); i++) {
                int a = node + nums[i];
                if(a == goal) return move+1;
                if(a >= 0 && a <= 1000 && !visited[a]) {
                    q.push({a, 1 + move});
                    visited[a] = 1;
                }
                
                a = node - nums[i];
                if(a == goal) return move+1;
                if(a >= 0 && a <= 1000 && !visited[a]) {
                    q.push({a, 1+move});
                    visited[a] = 1;
                }
                
                a = node ^ nums[i];
                if(a == goal) return move+1;
                if(a >= 0 && a <= 1000 && !visited[a]) {
                    q.push({a, 1+move});
                    visited[a] = 1;
                }
            }
        }
        
        return -1;
    }
};