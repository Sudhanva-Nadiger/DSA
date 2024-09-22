class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& b) {
        set<string> st(b.begin(), b.end());
        int c = 0;
        for(auto it : message) {
            c += st.count(it);
        }
        return c >= 2;
    }
};