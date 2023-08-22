class Solution {
public:
    unordered_set<char> st;
    
    bool f(char c) {
        return st.count(c);    
    }
    string sortVowels(string s) {
        string t = "AEIOUaeiou";
        for(auto it: t) st.insert(it);
        
        vector<char> arr;
        
        for(auto it : s) {
            if(f(it)) {
                arr.push_back(it);
            }    
        }
        
        sort(begin(arr), end(arr));
        
        int i = 0;
        for(auto& it : s) {
            if(f(it)) {
                it = arr[i++];
            }
        }
        
        return s;
    }
};