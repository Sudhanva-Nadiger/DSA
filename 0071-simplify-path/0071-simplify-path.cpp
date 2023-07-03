class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        
        vector<string> arr;
        string t = "";
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/') {
                arr.push_back(t);
                t = "";
            }else {
                t.push_back(path[i]);
            }
        }
        
        stack<string> st;
        for(auto it : arr) {
            if(it == "..") {
                if(st.size()) {
                    st.pop();
                }
            }else {
                if(it != "" && it != ".") {
                    st.push(it);
                }
            }
        }
        
        if(st.size() == 0) return "/";
        
        string ans = "";
        while(st.size()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};