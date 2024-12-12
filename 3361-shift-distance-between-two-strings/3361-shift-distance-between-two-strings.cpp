class Solution {
public:
    #define ll long long
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int mod = 26;
        ll max = numeric_limits<ll>::max();
        vector<vector<ll>> adj(mod, vector<ll>(26, max));
        
        for(int i = 0; i < mod; i++) {
            adj[i][i] = 0ll;
            
            int next = (i+1)%mod;
            
            adj[i][next] = (ll)nextCost[i];
            
            int prev = (i-1+mod)%mod;
            
            adj[i][prev] = (ll)previousCost[i];
        }
        
        
        for(int k = 0; k < mod; k++) {
            for(int i = 0; i < mod; i++) {
                for(int j = 0; j < mod; j++) {
                    if(adj[i][k] != max && adj[k][j] != max) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        
        ll ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans += adj[s[i]-'a'][t[i]-'a'];
        }
        return ans;
    }
};