class ATM {
    vector<int> arr;
    unordered_map<int, int> mp;
public:
    ATM() {
        arr.resize(5);
        mp[0] = 20;
        mp[1] = 50;
        mp[2] = 100;
        mp[3] = 200;
        mp[4] = 500;
    }
    
    int getNote(int index) {
        return mp[index];
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < banknotesCount.size(); i++) {
            arr[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        int val = amount;
        for(int i = arr.size()-1; i >= 0; i--) {
            int note = getNote(i);
            int req = amount/note;
            
            req = min(req, arr[i]);
            
            amount -= note*req;
        }
        
        if(amount != 0) return {-1};
        
        vector<int> ans(5);
        amount = val;
        
        for(int i = arr.size()-1; i >= 0; i--) {
            int note = getNote(i);
            int req = amount/note;
            
            req = min(req, arr[i]);
            
            arr[i] -= req;
            ans[i] += req;
            
            amount -= note*req;
        }
        
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */