class Solution {
public:
    int bs(vector<int>& nums, int left, int right, int target) {
        
        int ans = -1;
        while(left <= right) {
            int mid = (left+right)/2;
            
            if(nums[mid] <= target) {
                ans = mid;
                left = mid+1;
            }else {
                right = mid-1;
            }
        }
        
        return ans;
    }
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int target = nums[i] +nums[j];
                int index = bs(nums, j+1, n-1, target-1);
                if(index == -1) index = j;
                ans += max(0, index-j);
            }
        }
        
        return ans;
    }
};