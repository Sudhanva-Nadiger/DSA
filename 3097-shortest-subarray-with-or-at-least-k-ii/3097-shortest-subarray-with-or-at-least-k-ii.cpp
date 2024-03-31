class Solution {
public:
    int getNum(vector<int>& arr) {
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > 0) {
                ans += (1<<i);
            }
        }
        
        return ans;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        
        if(maxi >= k) return 1;
        
        int j = 0, ans = 1e9;
        vector<int> arr(32);
        for(int i = 0; i < nums.size();  i++) {
            int num = nums[i];
            
            for(int i = 0; i <= 31; i++) {
                if(num&(1<<i)) {
                    arr[i]++;
                }
            }
            
            
            while(getNum(arr) >=  k) {
                ans = min(ans, i-j+1);
            
                for(int k = 0; k <= 31; k++) {
                    if(nums[j]&(1<<k)) {
                        arr[k]--;
                    }
                }
                
                j++;
            }
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};