class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int j = 0;
        int cost = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) {
                cost += abs(s[i]-t[i]);
            }
            
            while(cost > maxCost) {
                if(s[j] != t[j]) {
                    cost -= abs(s[j]-t[j]);
                }
                
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
    }
};