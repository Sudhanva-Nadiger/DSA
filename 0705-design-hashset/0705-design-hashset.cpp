class MyHashSet {
    int n = 1e5+1;
    vector<vector<int>> dp;
public:
    MyHashSet() {
        dp = vector<vector<int>>(n+1);
    }
    
    void add(int key) {
        int r = key%n;
        bool found = false;
        
        for(int i : dp[r]) {
            if(i == key) {
                found = true;
                break;
            }
        }
        
        if(!found) {
            dp[r].push_back(key);
        }
    }
    
    void remove(int key) {
        int r = key%n;
        
        int found = -1;
        
        for(int i = 0; i < dp[r].size(); i++) {
            if(dp[r][i] == key) {
                found = i;
                break;
            }
        }
        
        if(found != -1) {
            int t = dp[r][found];
            dp[r][found] = dp[r][dp[r].size()-1];
            dp[r][dp[r].size()-1] = t;
            
            dp[r].pop_back();
        }
    }
    
    bool contains(int key) {
        int r = key%n;
        
        for(int it : dp[r]) {
            if(it == key) {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */