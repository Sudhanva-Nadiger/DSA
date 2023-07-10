class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProduct = 1;
        int maxProduct = 1;
        int ans = numeric_limits<int>::min();
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(minProduct, maxProduct);
            }
            
            minProduct = min(nums[i], nums[i]*minProduct);
            maxProduct = max(nums[i], nums[i]*maxProduct);
            
            ans = max({ans, minProduct, maxProduct});
        }
        
        return ans;
    }
};