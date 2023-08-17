class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        
        while(q.size()) {
            auto front = q.front();
            int i = front.first;
            int j = front.second;
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(ni >= 0 && nj >= 0 && ni < m && nj < n && dist[ni][nj] > dist[i][j] + 1) {
                    q.push({ni, nj});
                    dist[ni][nj] = 1 + dist[i][j];
                }
            }
        }
        
        return dist;
    }
};