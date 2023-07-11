class Solution {
public:
    int dp[2000][1001];
    bool f(unordered_map<int, int>& mp,vector<int>& nums, int n,int i, int k) {
        if(i == n-1) {
            return true;
        }
        
        if(i >= n) return false;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        for(int ind = -1; ind <= 1; ind++) {
            int jump = k+ind;
            
            if(jump > 0) {
                if(mp.find(jump + nums[i]) != mp.end()) {
                    bool found = f(mp,nums, n, mp[jump+nums[i]], jump);
                    if(found) {
                        return dp[i][k] = true;
                    }
                }
            }
        }
        
        return dp[i][k] = false;
    }
    bool canCross(vector<int>& stones) {
        memset(dp, -1, sizeof dp);
        unordered_map<int, int> mp;
        for(int i = 0; i < stones.size(); i++) {
            mp[stones[i]] = i;
        }
        
        if(stones[1] != stones[0]+1) return false;
        
        return f(mp, stones, stones.size(), 1, 1);
    }
};