class Solution {
public:
    int dp[10001];
    int f(vector<vector<int>>& arr, int i) {
        if(i == arr.size()) {
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        //take
        int id = i+1;
        if(i < arr.size()-1 && arr[i+1][0] == arr[i][0]+1) {
            id = i+2;
        }
        int take = arr[i][0]*arr[i][1] + f(arr, id);
        // nottake
        int notTake = f(arr, i+1);
        
        return dp[i] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it : nums)
            mp[it]++;
        
        vector<vector<int>> arr;
        for(auto it :mp) {
            arr.push_back({it.first, it.second});
        }
        
        sort(begin(arr), end(arr));
        memset(dp, -1, sizeof dp);
        return f(arr, 0);
    }
};