class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
    
        for(int i = 0; i <= n - 3; i+=3) {
            if(nums[i+2] - nums[i] > k) {
                return {};
            }
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < n-2; i+=3) {
            vector<int> v;
            for(int j = i; j <= i+2; j++) {
                v.push_back(nums[j]);
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};