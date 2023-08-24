class Solution {
public:
    int bs(vector<vector<int>>& nums, int l, int r, int target) {
        int ans = 1e9;
        
        while(l <= r) {
            int mid = (l+r)/2;
            
            if(nums[mid][0] > target) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return ans;
    }
    
    int dp[100001][3];
    int f(vector<vector<int>>& nums, int i, int count) {
        if(count == 0 || i >= nums.size()) {
            return 0;
        }
        
        if(dp[i][count] != -1) return dp[i][count];
        
        int take = nums[i][2];
        int nextId = bs(nums, i+1, nums.size()-1, nums[i][1]);
        take += f(nums, nextId, count-1);
        
        int notTake = f(nums, i+1, count);
        
        return dp[i][count] = max(take, notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));
        memset(dp, -1, sizeof dp);
        return f(events, 0, 2);
    }
};