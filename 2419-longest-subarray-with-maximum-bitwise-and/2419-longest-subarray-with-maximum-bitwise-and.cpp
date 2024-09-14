class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(begin(nums),end(nums));
        
        int maxLength = 0;
        
        for(int i = 0;i < nums.size();i++){
            int len = 0;
            while( i < nums.size() and nums[i] == maxi){
                len++;
                i++;
            }
            
            maxLength = max(maxLength,len);
        }
        
        return maxLength;
        
    }
};