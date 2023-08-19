class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n-2;) {
            if(nums[i+1]-nums[i] == nums[i+2]-nums[i+1]) {
                int count = 3;
                int j = i+3;
                int d = nums[i+1]-nums[i];
                
                while(j < n && nums[j]-nums[j-1] == d) {
                    count++;
                    j++;
                }
                
                i = j-1;
                
                ans += (count)*(count+1)/2 - max(2*count-1, 0);
            } else {
                i++;
            }
        }
        
        return ans;
    }
};