class MagicDictionary {
    unordered_set<string> st;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto it : dictionary) {
            st.insert(it);
        }
    }
    
    bool search(string str) {
        for(int i = 0; i < str.size(); i++) {
            char ch = str[i];
            
            for(int j = 0; j < 26; j++) {
                char newCh = ('a' + j);
                if(ch == newCh) continue;
                
                str[i] = newCh;
                
                if(st.count(str)) {
                    return true;
                }
            }
            
            str[i] = ch;
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */