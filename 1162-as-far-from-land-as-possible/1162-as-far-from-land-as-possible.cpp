class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i = 0;i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    dist[i][j] = 0;
                }
            }
        }
        
        int dx[]= {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        int ans = -1;
        
        while(q.size()) {
            auto front = q.front();
            q.pop();
            
            int wt = front.first;
            int i = front.second.first;
            int j = front.second.second;
            
            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(ni >= 0 && nj >= 0 && ni < n && nj < n) {
                    if(dist[ni][nj] > wt + abs(i-ni) + abs(j-nj)) {
                        dist[ni][nj] = wt + abs(i-ni) + abs(j-nj);
                        q.push({dist[ni][nj], {ni, nj}});
                        ans = max(ans, dist[ni][nj]);
                    }
                }
            }
        }
        
        return ans;
    }
};