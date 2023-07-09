class Solution {
public:
    int dp[100001][3];
    int ans = 0;
    int f(vector<int>& a, vector<int>& b, int i, int flag) {
        if(i >= a.size()) return 0;
        
        int& st = dp[i][flag];
        if(st != -1) return st;
        
        if(flag == 0) {
            int pick1 = 1+f(a, b, i+1, 1);
            int pick2 = 1+f(a, b, i+1, 2);
            int notPick = f(a, b, i+1, 0);
            
            st = max({pick1, pick2, notPick});
            ans = max(ans, st);
            return st;
        }else if(flag == 1) {
            int pick1 = 0;
            int pick2 = 0;
            
            if(a[i-1] <= a[i]) {
                pick1 = 1+f(a, b, i+1, 1);
            }
            if(a[i-1] <= b[i]) {
                pick2 = 1+f(a, b, i+1, 2);
            }
            
            st = max(pick1, pick2);
            ans = max(ans, st);
            return st;
        }else if(flag == 2) {
            int pick1 = 0;
            int pick2 = 0;
            
            if(b[i-1] <= a[i]) {
                pick1 = 1+f(a, b, i+1, 1);
            }
            if(b[i-1] <= b[i]) {
                pick2 = 1+f(a, b, i+1, 2);
            }
            
            st = max(pick1, pick2);
            ans = max(ans, st);
            
            return st;
        }
        
        return st = 0;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return f(nums1, nums2, 0, 0);
    }
};