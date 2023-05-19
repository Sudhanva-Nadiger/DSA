class Solution {
public:
    void getZor(vector<int>& nums, int& zor) {
        
        for(int it :nums) {
            zor ^= it;
        }
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int takeNums1 = nums2.size()%2 == 1;
        int takeNums2 = nums1.size()%2 == 1;
        
        int zor = 0;
        
        if(takeNums1) {
            getZor(nums1, zor);
        }
        
        if(takeNums2) {
            getZor(nums2, zor);
        }
        
        return zor;
    }
};