class Solution {
public:
    int f(int arr[], int n, int k) {
        int sum = 0;
        int maxSum = -1e9;
        set<int> st = {0};
        int j =  0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            auto it =st.lower_bound(sum-k);
            if(it != st.end()) {
                maxSum = max(maxSum, sum-*it);
            }
            st.insert(sum);
        }
        
        return maxSum;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int numRow= matrix.size();
        int numCol = matrix[0].size();
        int temp[numRow];
        int ans = -1e9;
        for(int left = 0; left < numCol; left++) {
            memset(temp, 0, sizeof temp);
            
            for(int right = left; right < numCol; right++) {
                for(int i = 0; i < numRow; i++) {
                    temp[i] += matrix[i][right];
                }
                
                int t = f(temp, numRow, k);
                if(t <= k) {
                    ans = max(ans, t);
                }
            }
        }
        
        return ans;
    }
};