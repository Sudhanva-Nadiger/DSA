class Solution {
public:
    map<int, vector<int>> mp;
    vector<int> f(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> right(n, n);
        
        for(int i = n-1; i >= 0; i--) {
            while(st.size() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            
            if(st.size()) {
                right[i] = st.top();
            }
            
            st.push(i);
            
            int j = n - i - 1;
            mp[nums[j]].push_back(j);
        }
        
        return right;
    }
    
    
    int bs(vector<int>& nums, int target) {
        int ans = -1;
        int i = 0, j = nums.size()-1;
        
        while(i <= j) {
            int mid = (i+j)/2;
            
            if(nums[mid] <= target) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid -1;
            }
        }
        
        return ans;
    }
    
    long long numberOfSubarrays(vector<int>& nums) {
        auto right = f(nums);
        int n = nums.size();
        long long ans = 0;
        
        // for(int i = 0; i < n; i++) cout << right[i] << " ";
        
        for(int i = 0; i < n; i++) {
            int id = right[i];
            
            auto& v = mp[nums[i]];
            
            int low = bs(v, i);
            int high = bs(v, id);
            
            if(low == -1 || high == -1) ans += 1;
            else
                ans += (high - low + 1);
        }
        return ans;
    }
};