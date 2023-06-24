class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long m = (long long)mass;
        
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] <= m) {
                m += (long long)nums[i];
            }else {
                break;
            }
            
            i++;
        }
        
        return i == nums.size();
    }
};