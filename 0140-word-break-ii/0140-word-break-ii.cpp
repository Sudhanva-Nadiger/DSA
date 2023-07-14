class Solution {
public:
    vector<vector<string>> res;
    vector<string> t;
    unordered_set<string> st;
    
    void f(string& s, int index) {
        if(index == s.size()) {
            res.push_back(t);
            return;
        }
        string temp;
        for(int i = index; i < s.size(); i++) {
            temp.push_back(s[i]);
            if(st.find(temp) != st.end()) {
                t.push_back(temp);
                f(s,i+1);
                t.pop_back();
            }
        }
        
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it : wordDict) {
            st.insert(it);
        }
        
        f(s, 0);
        vector<string> ret;
        
        for(auto it : res) {
            string temp = "";
            for(auto str : it) {
                temp += str + " ";
            }
            temp.pop_back();
            ret.push_back(temp);
        }
        return ret;
    }
};