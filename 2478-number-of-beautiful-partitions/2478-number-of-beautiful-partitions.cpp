class Solution {
public:
    bool isPrime(int n) {
        return (n == 2 || n == 3 || n == 5 || n == 7);
    }
    
    bool isBeautiful(string& s) {
        return (isPrime(s[0]-'0') && (!isPrime(s.back()-'0')));    
    }
    
    int dp[1000][1000];
    int mod = 1e9 + 7;
    int f(string& s, int index, int k, int minLength) {        
        if(index >= s.size()) {
            return k == 0;
        }
        
        if(k < 0 || (s.size()-index < k) || (s.size()-index < minLength)) return 0;
        if(!isPrime(s[index]-'0')) {
            return 0;
        }
        
        if(dp[index][k] != -1) return dp[index][k];
        
        string temp = s.substr(index, minLength-1);
        
        int ans = 0;
        for(int i = index+minLength-1; i <= s.size()-k; i++) {
            temp.push_back(s[i]);
            if(isBeautiful(temp)) {
                ans = (ans + f(s, i+1, k-1, minLength))%mod;
            }
        }
        
        return dp[index][k] = ans%mod;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        if(k == s.size()) return 0;
        memset(dp, -1, sizeof dp);
        return f(s, 0, k, minLength);
    }
};