class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> arr;
        
        for(int i = 0; i < nums.size();i++) {
            arr.push_back({nums[i], i});
        }
        
        sort(begin(arr), end(arr));
        int mini = arr[0].second;
        int ans = 0;
        
        for(int i = 1; i < arr.size(); i++) {
            ans = max(ans, arr[i].second - mini);
            mini = min(mini, arr[i].second);
        }
        return ans;
    }
};