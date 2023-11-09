class Solution {
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s) {
        int ans = 0, n = s.size();
        
        for(int i = 0; i < n; ) {
            long long j = i, count = 0ll;
            
            while(j < n && s[j] == s[i]) {
                count++;
                j++;
            }
            
            i = j;
            ans = (ans + ((count*(count+1))%mod)/2)%mod;
        }
        
        return ans;
    }
};