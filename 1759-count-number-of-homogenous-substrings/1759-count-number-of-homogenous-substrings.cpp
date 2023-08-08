class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int n = s.size();
        int mod = 1e9+7;
        
        for(int i = 0; i < n;) {
            int j = i;
            long long count = 0;
            while(s[j] == s[i]) {
                count++;
                j++;
            }
            
            i = j;
            
            long long t = ((count)*(count+1))/2;
            ans = (ans + t)%mod;
        }
        
        return ans;
    }
};