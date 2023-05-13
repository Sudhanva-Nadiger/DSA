class Solution {
public:
    unordered_map<int, int> mp;
    int ans = 0;
    
    void f(vector<int>& nums, int i, int k) {
        if(i >= nums.size()) {
            return;
        }
        
        // take current element
        if(!mp[nums[i]-k] and !mp[nums[i]+k]) {
             mp[nums[i]]++;
             ans++;
             f(nums, i+1, k);
             mp[nums[i]]--;
        }
        
        // go to next element
        f(nums, i+1, k);
        
        return;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        f(nums, 0, k);
        return ans;
    }
};