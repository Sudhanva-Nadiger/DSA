class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int window = 2*k+1;
        int c = window;
        int n = nums.size();
                vector<int> ans(n, -1);

        if(window > n) {
            return ans;
        }
        
        long long int sum = 0;
        
        for(int i = 0; i < window; i++) {
            sum += (long long)nums[i];    
        }
        
        int i = k, j = window;
        
        ans[i++] = sum/c;
        
       while(j < n) {
           sum -= nums[j-window];
           sum += (long long)nums[j];
           ans[i++] = sum/c;
           j++;
       }
        return ans;
    }
};