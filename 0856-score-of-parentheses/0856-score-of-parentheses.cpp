class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;
        
        for(char it: s) {
            if(it == '(') {
                st.push(score);
                score = 0;
            }else {
                score = st.top() + max(2*score, 1);
                st.pop();
            }
        }
        
        return score;
    }
};