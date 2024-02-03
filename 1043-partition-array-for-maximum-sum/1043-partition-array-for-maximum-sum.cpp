class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& arr,int index,int k){
        if(index >= arr.size()){
            return 0;
        }
        if(dp[index] != -1) return dp[index];
        int ans = INT_MIN;
        int mx = 0;
        int count = 0;
        for(int i = index;i<index+k and i < arr.size();i++){
            mx = max(mx,arr[i]);
            count++;
            int temp = mx*count + solve(arr,i+1,k);
            ans = max(ans,temp);
        }
        
        return dp[index] = ans;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp = vector<int> (arr.size()+1,-1);
        return solve(arr,0,k);
    }
};