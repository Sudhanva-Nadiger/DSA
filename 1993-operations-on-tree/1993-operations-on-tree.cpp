class LockingTree {
    vector<vector<int>> tree;
    int n;
    vector<int> parent;
    unordered_map<int, int> locked;
    
    bool isLocked(int num) {
        return (locked.find(num) != locked.end());
    }
    
    bool hasAtleastOneLockedChild(int u) {
        bool ans = isLocked(u);
        
        for(int v: tree[u]) {
            ans = ans || hasAtleastOneLockedChild(v);
        }
        
        return ans;
    }
    
    void unlockChildren(int num) {
        for(int v: tree[num]) {
            locked.erase(v);
            unlockChildren(v);
        }
    }
    
    bool hasNoLockedPar(int u) {
        if(u == -1) return true;
        
        if(isLocked(u)) return false;
        
        return hasNoLockedPar(parent[u]);
    }

public:
    LockingTree(vector<int>& parent) {
        n = parent.size();
        this->parent = parent;
        tree.resize(n);
        
        for(int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(isLocked(num)) {
            return false;
        }
        
        locked[num] = user;
        
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!isLocked(num) || locked[num] != user) {
            return false;
        }
        
        locked.erase(num);
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(isLocked(num)) return false;
        
        if(hasAtleastOneLockedChild(num) && hasNoLockedPar(num)) {
            unlockChildren(num);
            locked[num] = user;
            return true;
        }
        
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */