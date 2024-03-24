class Solution {
public:
    #define ll long long
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<ll> ans;
        
        set<pair<ll, ll>> st;
        map<ll, ll> mp;
        
        st.insert({freq[0], nums[0]});
        mp[nums[0]] = freq[0];
        
        ans.push_back(st.rbegin()->first);
        
        for(int i = 1; i < n; i++) {
            int curr = nums[i];
            
            if(mp.find(curr) != mp.end()) {
               
                ll fr = mp[curr];
                auto it = st.find({fr, curr});
                
                ll count = it->first;
                ll val = it->second;
                
                st.erase(it);
                mp.erase(val);
                
                count += freq[i];
                
                if(count > 0) {
                    st.insert({count, val});
                    mp[val] = count;
                }
                
            } else {
                st.insert({freq[i], curr});
                mp[curr] = freq[i];
            }
            
            if(st.size()) {
                ans.push_back(st.rbegin()->first);
            } else {
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};