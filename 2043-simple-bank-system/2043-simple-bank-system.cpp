class Bank {
    vector<long long> arr;
public:
    Bank(vector<long long>& balance) {
        arr = balance;
        arr.insert(arr.begin(), 0);
    }
    
    bool isPossibleTransaction(int account, long long money) {
        return arr[account] >= money;
    }
    
    bool isValidAccount(int account) {
        return account <= arr.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isValidAccount(account1) || !isValidAccount(account2) || !isPossibleTransaction(account1, money)) return false;
        
        withdraw(account1, money);
        deposit(account2, money);
        
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isValidAccount(account)) return false;
        
        arr[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValidAccount(account) || !isPossibleTransaction(account, money)) return false;
        
        arr[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */