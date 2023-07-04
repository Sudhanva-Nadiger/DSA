class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        char sign = '+';
        int num = 0;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                num = num*10 +  (s[i]-'0');
            }
            
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i ==  s.size()-1) {
                if(sign == '+') {
                    st.push(num);
                }else if(sign == '-') {
                    st.push(-num);
                }else {
                    if(sign == '*') {
                        num = st.top()*num;
                    }else {
                        num = st.top()/num;
                    }
                    st.pop();
                    st.push(num);
                }
                
                num = 0;
                sign = s[i];
            }
        }
        
        int ans = 0;
        while(st.size()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};