class Solution {
public:
    int f(int arr[], int n, int target) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(mp.find(sum-sum) != mp.end()) {
                count += mp[sum-target];
            }
            
            mp[sum]++;
        }
        
        return count;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int numRow = matrix.size();
        int numCol = matrix[0].size();
        int ans = 0;
        int dp[numRow];
        
        for(int left = 0; left < numCol; left++) {
            memset(dp, 0, sizeof dp);
            
            for(int right = left; right < numCol; right++) {
                for(int i = 0; i < numRow; i++) {
                    dp[i] += matrix[i][right];
                }
                
                ans += f(dp, numRow, target);
            }
        }
        
        return ans;
    }
};