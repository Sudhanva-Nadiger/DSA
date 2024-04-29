class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        
        
        
        for(int i = 0; i < 30; i++) {
            int zero = 0, one = 0;
            
            for(auto it : nums) {
                if(!(it&(1<<i))) {
                    zero++;
                } else {
                    one++;
                }
            }
            
            int reqBit = ((k&(1<<i)) != 0);
            int currBit = (one%2);

            
            if(reqBit != currBit) {
                ans += 1;
            }
        }
        
        return ans;
    }
};