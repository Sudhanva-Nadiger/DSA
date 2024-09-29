class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = 1e9;
        
        for(auto it : nums) {
            int sum = 0;
            while(it) {
                sum += it%10;
                it/=10;
            }
            mini = min(mini, sum);
        }
        
        return mini;
    }
};