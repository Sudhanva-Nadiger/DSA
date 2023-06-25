class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sum = accumulate(nums.begin(), nums.end(), 0ll);
        
        long long target = abs(goal-sum);
        
        int ans = 0;
        if(target == 0) return ans;
        
        ans += target/limit;
        
        ans += (target%limit == 0 ? 0 : 1);
        
        return ans;
    }
};