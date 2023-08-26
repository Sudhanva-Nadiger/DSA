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
    
    int validSubarraySize(vector<int>& nums, int t) {
        int n = nums.size();
        auto arr = f(nums);
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > t) return 1;
            
            int l = arr[0][i];
            int r = arr[1][i];
            
            int tot = r-l-1;
            
            if(nums[i] > t/tot) {
                return tot;
            }
        }
        return -1;
    }
};