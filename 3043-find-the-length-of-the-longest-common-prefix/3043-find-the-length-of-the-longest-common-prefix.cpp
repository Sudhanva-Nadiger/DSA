class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_set<string> st;
        
        for(auto it : arr1) {
            string s = to_string(it);
            string temp = "";
            
            for(auto c : s) {
                temp.push_back(c);
                st.insert(temp);
            }
        }
        
        for(auto it : arr2) {
            string s = to_string(it);
            string temp = "";
            
            for(auto c : s) {
                temp.push_back(c);
                if(st.count(temp)) {
                    ans = max(ans, (int)temp.size());
                }
            }
        }
        
        return ans;
    }
};