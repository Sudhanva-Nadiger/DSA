class Solution {
public:
    bool f(int nums[],int n, int k, int target) {
        if(k > n) return false;
        
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        if(sum <= target) return true;
        
        for(int i = k; i < n; i++) {
            sum -= nums[i-k];
            sum += nums[i];
            
            if(sum <= target) {
                return true;
            }
        }
        
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int numRow = mat.size();
        int numCol = mat[0].size();
        int ans = 0;
        for(int left = 0;left < numCol; left++) {
            
            int temp[numRow];
            memset(temp, 0, sizeof temp);
            
            for(int right = left; right < numCol; right++) {
                for(int i = 0; i < numRow; i++) {
                    temp[i] += mat[i][right];
                }
                
                bool ok = f(temp, numRow, right-left+1, threshold);
                if(ok) ans = max(ans, right-left+1);
            }
        }
        
        return ans;
    }
};