class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> mp;
        int n = arr.size();
        
        for(int i = n-1; i >= 0; i--) {
            if(mp.find(arr[i]+diff) != mp.end()) {
                mp[arr[i]] = 1+mp[arr[i]+diff];
            }else {
                mp[arr[i]] = 1;
            }
        }
        
        int ans = 0;
        for(auto it : mp) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};