class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ')' || s[i] == '(') {
                
                if(s[i] == ')') {
                    if(st.size() && s[st.top()] == '(') {
                        st.pop();
                    } else {
                        st.push(i);
                    }
                } else {
                    st.push(i);
                }
            }    
        }
        
        string ans = "";
        
        for(int i = n-1; i >= 0; i--) {
            if(st.size() && st.top() == i) {
                st.pop();
                continue;
            }
            
            ans.push_back(s[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};