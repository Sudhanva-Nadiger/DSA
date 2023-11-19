class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<int> arr(50001, 0);
        for(auto it : nums) arr[it] = 1;
        int ans = 0;
        for(int i = 1; i < arr.size(); i++) {
            arr[i] += arr[i-1];
        }
        for(auto it : nums) {
            ans += arr[it-1];
        }
        return ans;
    }
};