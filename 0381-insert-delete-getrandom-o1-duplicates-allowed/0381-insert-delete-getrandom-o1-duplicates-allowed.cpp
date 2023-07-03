class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int> > mp;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = false;
        
        if(mp.find(val) == mp.end()) {
            flag = true;
        }
        
        nums.push_back(val);
        mp[val].insert(nums.size()-1);
        
        return flag;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) {
            return false;
        }
        
        int n = nums.size();
        if(nums[n-1] == val) {
            nums.pop_back();
            mp[val].erase(n-1);
            if(mp[val].size() == 0) {
                mp.erase(val);
            }
            return true;
        }
        
        int id = *mp[val].begin();
        mp[val].erase(id);
        if(mp[val].size() == 0) {
            mp.erase(val);
        }
        int lastNum = nums[n-1];
        mp[lastNum].erase(n-1);
        mp[lastNum].insert(id);
        swap(nums[id], nums[n-1]);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */