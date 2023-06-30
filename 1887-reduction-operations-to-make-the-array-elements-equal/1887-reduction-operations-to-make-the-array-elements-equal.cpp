class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int minEle = nums[0];
        map<int, int> mp;
        for(auto it : nums) {
            minEle = min(minEle, it);
            mp[it]++;
        }
        
        int ans = 0;
        
        int prevCount = 0;
        for(auto it : mp) {
            
            if(it.first == minEle) {
                continue;
            }
            
            prevCount += 1;
            
            ans += it.second*prevCount;
        }
        
        return ans;
    }
};