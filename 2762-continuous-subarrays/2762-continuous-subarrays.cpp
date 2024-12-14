class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int j = 0;
        long long ans = 0;
        multiset<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            
            while(*st.rbegin()-*st.begin()>2) {
                st.erase(st.find(nums[j++]));
            }
            
            ans+=i-j+1;
        }
        return ans;
    }
};