class Solution {
public:
    int dp[500000];
    int f(int n) {
        if(n == 1) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        if(n%2 == 0) {
            //even
            return dp[n] = 1+f(n/2);
        }
        
        return dp[n] = 1+f(3*n+1);
    }
    
    int getKth(int lo, int hi, int k) {
        memset(dp, -1, sizeof(dp));
        
        vector<pair<int,int>> arr;
        for(int i = lo; i <= hi; i++) {
            arr.push_back({i, f(i)});
        }
        
        sort(begin(arr), end(arr), [](auto a, auto b) {
            if(a.second == b.second) {
                return a.first <= b.first;
            }
            
            return a.second <= b.second;
        });
        
        return arr[k-1].first;
    }
};