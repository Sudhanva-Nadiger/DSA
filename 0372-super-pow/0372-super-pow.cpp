class Solution {
public:
    int mod = 1337;
    
    vector<int> half(vector<int> nums) {
        vector<int> ans;
        string number = "";
        for(auto it : nums) {
            number.push_back(it+'0');
        }
        
        int carry = 0;
        
        for(int i = 0; i < number.size(); i++) {
            int num = carry*10 + (number[i]-'0');
            if(num < 2) {
                if(ans.size())
                    ans.push_back(0);
                carry = num;
            } else {
                ans.push_back(num/2);
                carry = num%2;
            }
        }
        
        return ans;
    }
    
    int superPow(int a, vector<int> b) {
        if(b.size() == 1) {
            if(b[0] == 1) return a%mod;
            
            if(b[0] == 0) return 1;
        }
        
        bool isOdd = b.back()%2 == 1;
        
        long long ans = superPow(a, half(b))%mod;
        
        if(isOdd) {
            return (ans*ans)%mod*a%mod;
        }
        
        return (ans*ans)%mod;
    }
};