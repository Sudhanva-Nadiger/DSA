class Solution {
public:
    int dp[301];
    bool f(string& s, int ind, unordered_set<string>& st) {
        if(ind == s.size()) return true;
        
        if(dp[ind] != -1) return dp[ind];
        
        string t = "";
        
        bool ans = false;
        for(int i = ind; i < s.size(); i++) {
            t.push_back(s[i]);
            if(st.count(t)) {
                ans = ans || f(s, i+1, st);
            }
        }
        
        return dp[ind] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        memset(dp, -1, sizeof dp);
        return f(s, 0, st);
    }
};