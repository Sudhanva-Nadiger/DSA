#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

template <class T> using ordered_multi_set = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

class Solution {
public:
    int mod = 1e9 + 7;
    int createSortedArray(vector<int>& nums) {
        ordered_multi_set<int> st;
        int ans = 0;
        st.insert(nums[0]);
        unordered_map<int, int> mp;
        mp[nums[0]]++;
        
        for(int i = 1; i < nums.size(); i++) {
            auto it = st.lower_bound(nums[i]-1);
            
            if(it == st.end() || it == st.rend()) {
                
            } else {
                int c = st.order_of_key(*it);
                int t = min(c, (int)st.size()-c-mp[nums[i]]);
                ans = (ans + t)%mod;
            }
            
            st.insert(nums[i]);
            mp[nums[i]]++;
        }
        
        return ans;
    }
};