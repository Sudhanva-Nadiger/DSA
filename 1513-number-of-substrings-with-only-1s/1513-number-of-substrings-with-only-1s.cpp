class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        int n = s.size();
        int mod = 1e9+7;
        
        for(int i = 0; i < n;) {
            if(s[i] == '0') {
                i++;
                continue;
            }
            int j = i;
            long long count = 0;
            while(s[j] == '1') {
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