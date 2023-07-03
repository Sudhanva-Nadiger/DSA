class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        string ans = "";
        string t = "";
        
        for(auto it : s) {
            if(it == ' ') {
                if(t != "") {
                    ans = t + ' ' + ans;
                }
                
                t = "";
            }else {
                t += it;
            }
        }
        
        ans.pop_back();
        
        return ans;
    }
};