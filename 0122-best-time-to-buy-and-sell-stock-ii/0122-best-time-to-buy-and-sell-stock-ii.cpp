class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = 1e9;
        
        for(auto it : prices) {
            if(it < mini) {
                mini = it;
            }else if(it > mini) {
                ans += it-mini;
                mini = it;
            }
        }
        
        return ans;
    }
};