class AllOne {
    map<string,int> mp;
    map<int,set<string>> dict;
public:
    AllOne() {
        mp.clear();
        dict.clear();
    }
    
    void eraseEmpty(int key) {
        if(!dict[key].size()) {
            dict.erase(key);
        }
    }
    
    void inc(string key) {
        int prevCount = mp[key];
        int currCount = prevCount+1;
        
        dict[prevCount].erase(key);
        dict[currCount].insert(key);
        
        eraseEmpty(prevCount);
        
        mp[key] = currCount;
    }
    
    void dec(string key) {
        if(!mp.count(key)) return;
        
        int prevCount = mp[key];
        int currCount = prevCount-1;
        
        dict[prevCount].erase(key);
        if(currCount > 0)
            dict[currCount].insert(key);
        eraseEmpty(prevCount);
        eraseEmpty(currCount);
        
        if(currCount == 0) {
            mp.erase(key);
            return;
        }
        
        mp[key] = currCount;
    }
    
    string getMaxKey() {
        if(!dict.size()) return "";
        
        auto& st = dict.rbegin()->second;
        if(st.size()) {
            return *st.begin();
        }
        
        return "";
    }
    
    string getMinKey() {
        if(!dict.size()) return "";
        
        auto& st = dict.begin()->second;
        if(st.size()) {
            return *st.begin();
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */