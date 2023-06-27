class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> st;
        queue<string> q;

        for(auto it : words) {
            st.insert(it);
            if(it.size() == 1) {
                q.push(it);
            }
        }
        
        string ans = "";
        
        while(q.size()) {
            auto front = q.front();
            q.pop();
            
            if(front.size() >= ans.size()) {
                if(front.size() == ans.size()) {
                    ans = min(ans, front);
                }else {
                    ans = front;
                }
            }
            
            for(int i = 0; i < 26; i++) {
                front.push_back('a' + i);
                if(st.find(front) != st.end()) {
                    q.push(front);
                }
                front.pop_back();
            }
        }
        
        return ans;
    }
};