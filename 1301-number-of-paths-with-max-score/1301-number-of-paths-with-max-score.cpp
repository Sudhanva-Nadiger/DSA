class Solution {
public:
    int dp1[101][101], dp2[101][101][2001], mod = 1e9+7;
    int f(vector<string>& nums,int i, int j) {
        if(i < 0 || j < 0) {
            return -1e9;
        }
        
        if(i == 0 && j == 0) {
            return 0;
        }
        
        if(nums[i][j] == 'X') {
            return -1e9;
        }
        
        if(dp1[i][j] != -1) return dp1[i][j];
        
        int m1 = f(nums, i-1, j);
        int m2 = f(nums, i, j-1);
        int m3 = f(nums, i-1, j-1);
        
        return dp1[i][j] = max({m1, m2, m3}) + (nums[i][j] != 'S' ? nums[i][j]-'0': 0);
    }
    
    int f(vector<string>& nums,int i, int j, int score, int maxSum) {
        if(i < 0 || j < 0) {
            return 0;
        }
        
        if(i == 0 && j == 0) {
            return score == maxSum;
        }
        
        if(nums[i][j] == 'X') {
            return 0;
        }
        
        if(dp2[i][j][score] != -1) return dp2[i][j][score];
        
        int m1 = f(nums, i-1, j, score + (nums[i][j] != 'S' ? nums[i][j]-'0': 0), maxSum);
        int m2 = f(nums, i, j-1, score + (nums[i][j] != 'S' ? nums[i][j]-'0': 0), maxSum);
        int m3 = f(nums, i-1, j-1, score + (nums[i][j] != 'S' ? nums[i][j]-'0': 0), maxSum);
        
        return dp2[i][j][score] = (m1+m2+m3)%mod;
    }
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        memset(dp1, -1, sizeof dp1);
        int m = board.size(), n = board[0].size();
        int maxSum = f(board, m-1, n-1);
        if(maxSum < 0) return {0, 0};
        memset(dp2, -1, sizeof dp2);
        return {maxSum, f(board, m-1, n-1, 0, maxSum)};
    }
};