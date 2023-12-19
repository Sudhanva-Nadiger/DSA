class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto it : knowledge) {
            mp[it[0]] = it[1];
        }
        string ans = "";
        bool flag = true;
        int start = -1;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                flag = false;
                start = i;
            } else if(s[i] == ')') {
                flag = true;
                
               string t = s.substr(start+1, i-start-1);
                if(mp.count(t)) {
                    ans += mp[t];
                } else {
                    ans += "?";
                }
            } else if(flag){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};