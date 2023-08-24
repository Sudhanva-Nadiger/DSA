class Solution {
public:
    int bs(vector<vector<int>>& nums, int l, int r, int target) {
        int ans = 1e9;
        
        while(l <= r) {
            int mid = (l+r)/2;
            
            if(nums[mid][0] >= target) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return ans;
    }
    
    int dp[100001];
    int f(vector<vector<int>>& nums, int i) {
        if(i >= nums.size()) {
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        int take = nums[i][2];
        int nextId = bs(nums, i+1, nums.size()-1, nums[i][1]);
        take += f(nums, nextId);
        
        int notTake = f(nums, i+1);
        
        return dp[i] = max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> nums;
        int n = profit.size();
        for(int i = 0; i < n; i++) {
            nums.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(begin(nums), end(nums));
        memset(dp, -1, sizeof dp);
        return f(nums, 0);
    }
};