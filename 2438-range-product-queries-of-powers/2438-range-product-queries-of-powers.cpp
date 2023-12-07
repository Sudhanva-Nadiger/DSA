#define ll long long

class Solution {
    const int logn = 30, mod = 1e9 + 7;
public:
    
    vector<ll> getPowersArr(int n) {
        vector<ll> powers;
        
        for(int i = logn; i >= 0; i--) {
            int pow = (1<<i);
            int count = n/pow;
            
            while(count--) {
                powers.push_back(pow);
            }
            
            n %= pow;
        }
        
        return powers;
    }
    
    ll getInv(ll x, ll n) {
        if(n == 0) return 1;
        
        ll ans = getInv(x, n/2)%mod;
        
        if(n&1) {
            return (ans*ans%mod*x%mod);
        } 
        
        return ans*ans%mod;
    }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> powers = getPowersArr(n);
        sort(powers.begin(), powers.end());
                
        int m = powers.size();
        vector<ll> prefixArr = powers;
        for(int i = 1; i < m; i++) {
            prefixArr[i] = (prefixArr[i]*prefixArr[i-1])%mod;
        }
        
        vector<ll> invArr(m);
        invArr[m-1] = getInv(prefixArr[m-1], mod-2)%mod;
        
        for(int i = m-2; i >= 0; i--) {
            invArr[i] = (invArr[i+1]*powers[i+1])%mod;
        }
        
        vector<int> ans;
        for(auto q : queries) {
            int l = q[0];
            int r = q[1];
            
            ans.push_back((prefixArr[r]*(l-1 >= 0 ? invArr[l-1] : 1LL))%mod);
        }
        
        return ans;
    }
};