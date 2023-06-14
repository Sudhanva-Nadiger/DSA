class Solution {
public:
    int minDifference(vector<int>& A) {
        sort(A.begin(), A.end());
        
        int n = A.size();
        if(n < 5) return 0;
        
        int ans = INT_MAX;
        
        return min({A[n - 1] - A[3], A[n - 2] - A[2], A[n - 3] - A[1], A[n - 4] - A[0]});
        
    }
};