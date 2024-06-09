class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(auto it : s) {
            if('0' <= it && it <= '9') {
                if(ans.size()) ans.pop_back();
            } else {
                ans.push_back(it);
            }
        }
        return ans;
    }
};