class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long second = numeric_limits<long long int>::max();
        
        vector<long long> up(n), down(n);
        up[0] = (long long)grid[0][0];
        down[n-1] = (long long)grid[1][n-1];
        
        for(int i = 1; i < n; i++) {
            up[i] = up[i-1] + (long long)grid[0][i];
        }
        
        for(int i = n-2; i >= 0; i--) {
            down[i] = down[i+1] + (long long)grid[1][i];
        }
        
        for(int i = 0; i < n; i++) {
            long long upSum = up[n-1]-up[i];
            long long downSum = down[0]-down[i];
            
            second = min(second, max(upSum, downSum));
        }
        
        return second;
    }
};