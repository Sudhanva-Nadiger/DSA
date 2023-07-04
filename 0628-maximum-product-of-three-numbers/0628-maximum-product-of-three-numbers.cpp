class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        
        int a = nums[n-1];
        int b = nums[0]*nums[1];
        
        return max({a*nums[n-2]*nums[n-3], b*nums[2], b*a});
    }
};