class Solution {
public:
    vector<string> ans;
    string t = "";
    void f(int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(t);
            return;
        }
        
        if(open < 0 || close < 0) {
            return;
        }
        
        if(close > open) {
            t.push_back(')');
            f(open, close-1);
            t.pop_back();
        }
        
        t.push_back('(');
        f(open-1, close);
        t.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        f(n, n);
        return ans;
    }
};