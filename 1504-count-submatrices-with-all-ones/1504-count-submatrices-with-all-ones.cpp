class Solution {
public:
    int f(int arr[], int n) {
        int ans = 0;
        int len = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i]) {
                len++;
            }else {
                len = 0;
            }
            
            ans += len;
        }
        
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0;
        int numRow = mat.size();
        int numCol = mat[0].size();
        int temp[numRow];
        
        for(int left = 0; left < numCol; left++) {
            memset(temp, 1, sizeof temp);
            
            for(int right = left; right < numCol; right++) {
                for(int i = 0; i < numRow; i++) {
                    if(temp[i]) {
                        temp[i] = mat[i][right];
                    }
                }
                
                ans += f(temp, numRow);
            }
        }
        
        return ans;
    }
};