class Solution {
public:
    bool f(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;
        
        for(auto it : nums) {
            sum += ceil((double)it/(double)divisor);
        }
        
        return sum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = 0, low = 1, high = 1e9;
        
        while(low <= high) {
            int mid = (low+high)/2;
            
            if(f(nums, threshold, mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};