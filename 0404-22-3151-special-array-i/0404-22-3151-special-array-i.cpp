class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int prev = -1;
        
        for(int it : nums) {
            int curr = it&1;
            
            if(curr == prev) return false;
            
            prev = curr;
        } 
        
        return true;
    }
};