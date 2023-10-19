class Solution {
public:
    int f(vector<int>& nums, int k) {
        int ans = 0, j = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            
            while(mp.size() > k) {
                mp[nums[j]]--;
                
                if(mp[nums[j]] == 0) {
                    mp.erase(nums[j]);
                }
                
                j++;
            }
            
            ans += (i-j+1);
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};