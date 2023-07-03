class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int m = s.size(), n = goal.size();
        if(m != n) return false;
        
        int first = -1;
        int second = -1;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != goal[i]) {
                if(first == -1) {
                    first = i;
                }else {
                    second = i;
                }
            }    
        }
        
        if(first == -1) {
            unordered_set<char> st(s.begin(), s.end());
            return st.size() < m;
        }
        if(first != 1 && second == -1) {
            return false;
        }
        
        swap(s[first], s[second]);
        
        return s == goal;
    }
};