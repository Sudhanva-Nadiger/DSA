class Solution {
public:
    using pip = pair<int, pair<int, int>>;
    const int inf = 1e9 + 9;
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        vector<vector<int>> dist(m+1, vector<int>(n+1, inf));
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while(pq.size()) {
            auto [effort, node] = pq.top();
            pq.pop();
            auto [i, j] = node;
            
            if(i == m-1 && j == n-1) {
                return effort;
            }
            
            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                    int newEffort = abs(heights[i][j] - heights[ni][nj]);
                    if(dist[ni][nj] > max(dist[i][j], newEffort)) {
                        dist[ni][nj] = max(dist[i][j],newEffort);
                        
                        pq.push({dist[ni][nj], {ni, nj}});
                    }
                }
            }
        }
        
        return -1;
    }
};