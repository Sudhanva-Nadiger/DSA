class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        int currReach = 0;
        int jump  = 0;
        
        for(int i = 0; i < nums.size()-1; i++) {
            maxReach = max(maxReach, i+nums[i]);
            
            if(i == currReach) {
                currReach = maxReach;
                jump++;
            }
        }
        return jump;
    }
};