class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int j = 0;
        int ans = 1;
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < n; i++) {
            while(nums[i]-nums[j] > 2*k){
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};