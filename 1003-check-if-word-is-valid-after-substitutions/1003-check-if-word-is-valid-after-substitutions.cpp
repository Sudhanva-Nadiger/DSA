class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'c') {
                if(st.size() < 2) {
                    return false;
                }else {
                    int c = st.top();
                    if(c != 'b') {
                        return false;
                    }
                    st.pop();
                    c = st.top();
                    if(c != 'a') {
                        return false;
                    }
                    st.pop();
                }
            }
            else
                st.push(s[i]);
        }
        
        
        return st.size() == 0;
    }
};