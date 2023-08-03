class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, true), right(n, true);
        
        int leftMax = nums[0];
        int rightMin = nums[n-1];
        
        for(int i = 1; i < n-1; i++) {
            left[i] = (nums[i] > leftMax);
            right[n-i-1] = (nums[n-i-1] < rightMin);
            
            leftMax = max(leftMax, nums[i]);
            rightMin = min(rightMin, nums[n-i-1]);
        }
        
        int ans = 0;
        for(int i = 1; i < n-1; i++) {
            if(left[i] && right[i]) {
                ans += 2;
            }else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};