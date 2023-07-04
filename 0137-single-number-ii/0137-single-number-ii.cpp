class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        int zor = 0;
        for(int i = 0; i < nums.size(); i++) {
            ones ^= nums[i];
            ones &= ~twos;
            twos ^= nums[i];
            twos &= ~ones;
        }
        
        return ones;
    }
};