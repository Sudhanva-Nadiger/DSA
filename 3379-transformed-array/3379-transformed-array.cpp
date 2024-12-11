class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            int newIndex = (i + nums[i] + 100*n)%n;
            
            ans[i] = nums[newIndex];
        }
        
        return ans;
    }
};