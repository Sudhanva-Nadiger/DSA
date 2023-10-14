class Solution {
public:
    int dp[501][501];
   int f(vector<vector<int>>& arr, int i, int taken) {
       if(taken >= arr.size()) return 0;
       if(i >= arr.size()) return 1e9;
       
       if(dp[i][taken] != -1) return dp[i][taken];
       
       // take
       int take = arr[i][0] + f(arr, i+1, taken+1+arr[i][1]);
       int notTake = 0 + f(arr, i+1, taken);
       
       return dp[i][taken] = min(take, notTake);
   } 
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> arr;
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) {
            arr.push_back({cost[i], time[i]});
        }
        
        return f(arr, 0, 0);
    }
};