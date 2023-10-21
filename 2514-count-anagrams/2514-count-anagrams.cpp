class Solution {
public:
    #define ll long long
    static const ll maxN = 1e5;
    ll mod = 1e9 + 7, fact[maxN+1], inv[maxN+1];
    
    ll exp(ll x, ll n) {
        if(n == 0) {
            return 1;
        }
        
        ll ans = exp(x, n/2)%mod;
        if(n%2 == 1) {
            return (((ans%mod*ans%mod)%mod)*x%mod)%mod;
        }
        
        return (ans%mod*ans%mod)%mod;
    }
    
    void evalFact(ll n) {
        fact[0] = 1;
        fact[1] = 1;
        
        for(ll i = 2; i <= n; i++) {
            fact[i] = (fact[i-1]*i)%mod;
        }
        
        inv[n] = exp(fact[n], mod-2)%mod;
        
        for(ll i = n; i >= 1; i--) {
            inv[i-1] = (inv[i]*(i))%mod;
        }
    }
    
    ll f(string& word) {
        vector<ll> freq(26);
        for(auto it : word) freq[it-'a']++;
        ll ans = fact[(int)word.size()];
        for(ll i = 0; i < 26; i++) {
            if(freq[i] > 1) {
                ans = (ans*inv[freq[i]])%mod;
            }
        }
        
        return ans%mod;
    }
    
    int countAnagrams(string s) {
        ll ans = 1;
        
        evalFact(s.size());
        
        stringstream ss(s);
        string word;
        while(!ss.eof()) {
            getline(ss, word, ' ');
            ans = (ans*f(word))%mod;
        }
        
        return ans;
    }
};