class Solution {
public:
    bool canConvertString(string s, string p, int k) {
        int n = s.size();
        int m = p.size();
        
        if(n != m) return false;
        
        unordered_map<int, int> mp;
        int mod = 26;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == p[i]) {
                continue;
            }
            
            int gap = p[i]-s[i];
            
            int id = (gap + mod)%mod;
            mp[id]++;
        }
        
        unordered_map<int, int> map;
        
        for(auto it : mp) {
            int count = it.second;
            int id = it.first;
            while(count--) {
                if(map.count(id) || id > k) return false;
                map[id]++;
                id += mod;
            }
        }
        
        return true;
    }
};