class Solution {
public:
    vector<vector<int>> f(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--) {
            while(st.size() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            if(st.size()) {
                right[i] = st.top();
            }
            
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        for(int i = 0; i < n; i++) {
            while(st.size() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            if(st.size()) {
                left[i] = st.top();
            }
            
            st.push(i);
        }
        
        return {left, right};
    }
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        auto arr = f(nums);
        vector<long long> pref(n, 0ll);
        for(int i = 0;i < n; i++) {
            if(i == 0) {
                pref[0] = (long long)nums[0];
            } else {
                pref[i] = (long long)nums[i] + pref[i-1];
            }
        }
        int mod = 1e9 + 7;
        long long ans = 0ll;
        for(int i = 0; i < n; i++) {
            int l = arr[0][i];
            int r = arr[1][i];
            
            long long sum = pref[r-1] - (l != -1 ? pref[l] : 0);
            
            ans = max(ans, (long long)((long long)sum*(long long)nums[i]));
        }
        
        return ans%mod;
    }
};