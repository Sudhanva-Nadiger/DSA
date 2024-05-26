class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for(auto it : nums1) {
            for(auto c : nums2) {
                ans += (it%(c*k) == 0);
            }
        }
        return ans;
    }
};