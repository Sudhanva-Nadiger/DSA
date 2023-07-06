class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for(int i = 0; i < s.size(); i++) {
            
            if(st.size() && st.top().first == s[i]) {
                if(st.top().second == k-1) {
                    st.pop();
                }else {
                    st.top().second++;
                }
            }else {
                st.push({s[i], 1});
            }
        }
        
        string ans = "";
        while(st.size()) {
            char ch = st.top().first;
            int count = st.top().second;
            st.pop();
            while(count--) {
                ans.insert(ans.begin(), ch);
            }
        }
        
        return ans;
    }
};