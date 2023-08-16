class Solution {
public:
    int dp[10][500];
    int f(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, int mask) {
        if(i == students.size()) {
            return 0;
        }
        
        if(dp[i][mask] != -1) return dp[i][mask];
        
        int ans = 0;
        for(int j = 0; j < mentors.size(); j++) {
            int pair = 0;
            if((mask & (1 << j)) == 0) {
                for(int index = 0; index < students[i].size(); index++) {
                    pair += (mentors[j][index] == students[i][index]);
                }
                
                pair += f(students, mentors, i+1, mask | (1 << j));
            }
            
            int notPair = f(students, mentors, i+1, mask);
            
            ans = max({ans, pair, notPair});
        }
        
        return dp[i][mask] = ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        memset(dp, -1, sizeof dp);
        return f(students, mentors, 0, 0);
    }
};