class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1;
        int j = 0;
        multiset<int> st;
        
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            
            while(*(st.rbegin())-*(st.begin()) > limit) {
                st.erase(st.find(nums[j]));
                j++;
            }
            
            ans = max(ans, i-j+1);
        }
        
        return ans;
    }
};