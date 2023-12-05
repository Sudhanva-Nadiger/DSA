class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                int gcd = __gcd(i, j);
                
                if(gcd != 1) continue;
                
                string s = to_string(j) + "/" + to_string(i);
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};