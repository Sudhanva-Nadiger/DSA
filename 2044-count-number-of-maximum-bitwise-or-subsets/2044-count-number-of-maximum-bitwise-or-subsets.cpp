class Solution {
public:
    int ans = 0;
    int res = 0;
    void maxOr(vector<int>& nums, int i, int t) {
        if(i == nums.size()) {
            ans = max(ans, t);
            return;
        };
        
        maxOr(nums, i+1, t | nums[i]);
        maxOr(nums, i+1, t);
    }
    
    void solve(vector<int>& nums, int i,int t) {
        if(i == nums.size()) {
            if(t == ans) {
                res++;
            }
            
            return;
        }
        
        solve(nums, i+1, t | nums[i]);
        solve(nums, i+1, t);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> arr(31);
        maxOr(nums, 0, 0);
        solve(nums, 0, 0);
        return res;
    }
};