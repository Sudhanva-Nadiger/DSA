class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib {1, 2};
        
        while(fib.back() < k) {
            int n = fib.size();
            fib.push_back(fib[n-1]+fib[n-2]);
        }
        
        int ans = 0, n = fib.size();
        for(int i = n-1; i >= 0; i--) {
            ans += (k/fib[i]);
            k %= fib[i];
        }
        
        return ans;
    }
};