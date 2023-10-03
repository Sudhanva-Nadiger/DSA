class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        
        for(int i : nums){
            mp[i]++;
        }
        int ans = 0;
        for(auto it : mp){
            int n = it.second;
            int add = n*(n-1)/2;
            ans += add;
        }
        
        return ans;
    }
};