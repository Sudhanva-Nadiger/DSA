class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int currReach = 0;
        int jump = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(maxReach < i) return false;
            
            maxReach = max(maxReach, i+nums[i]);
            
            if(i == currReach) {
                jump++;
                currReach = maxReach;
            }
        }
        
        return maxReach >= nums.size()-1;
    }
};