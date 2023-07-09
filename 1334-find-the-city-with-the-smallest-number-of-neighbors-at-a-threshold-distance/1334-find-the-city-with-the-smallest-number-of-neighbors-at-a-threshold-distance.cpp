class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        for(auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] >= 1e9 || dist[k][j] >= 1e9) {
                        continue;
                    }
                    
                    if(dist[i][j]> dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        
        int ans = 0;
        int count = 1e9;
        
        for(int i = 0; i < n; i++) {
            int c = 0;
            for(auto it : dist[i]) {
                if(it <= distanceThreshold) {
                    c++;
                }
            }
            
            if(c <= count) {
                count = c;
                ans = i;
            }
        }
        
        return ans;
    }
};