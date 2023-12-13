class Solution {
public:
    #define ll long long
    
    vector<vector<ll>> f(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> left(n, -1), right(n, n);
        stack<ll> st;
        
        for(int i = 0; i < n; i++) {
            while(st.size() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            if(st.size()) {
                left[i] = st.top();
            }
            
            st.push(i);
        }
        
        while(st.size()) {
            st.pop();
        }
        
        for(int i = n-1; i >= 0; i--) {
            while(st.size() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            if(st.size()) {
                right[i] = st.top();
            }
            
            st.push(i);
        }
        
        
        return {left, right};
    }
    
    ll computeSum(vector<vector<ll>>& arr, vector<int>& nums) {
        int n = nums.size();
        vector<ll> leftSum(n), rightSum(n);
    
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            int prev = arr[0][i];
            
            leftSum[i] += (ll)(i-prev)*(ll)nums[i];
            if(prev != -1) leftSum[i] += leftSum[prev];
            
            
            int j = n-i-1;
            int next = arr[1][j];
            rightSum[j] += (ll)(next-j)*(ll)nums[j];
            if(next != n) rightSum[j] += rightSum[next];
        }
        
        for(int i = 0; i < n; i++) {
            ll sum = leftSum[i] + rightSum[i] - nums[i];
            ans = max(ans, sum);
        }
        
        return ans;
    }
    
    long long maximumSumOfHeights(vector<int>& nums) {
        ll n = nums.size();
        
        
        vector<vector<ll>> arr = f(nums);
        return computeSum(arr, nums);
    }
};