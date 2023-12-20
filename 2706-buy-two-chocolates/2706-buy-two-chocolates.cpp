class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int ans = -1;
        
        for(int i = 0; i < prices.size(); i++) {
            for(int j = i+1;j < prices.size(); j++) {
                int diff = money - (prices[i]+prices[j]);
                if(diff >= 0) {
                    ans = max(ans, diff);
                }
            }
        }
        
        return ans == -1 ? money : ans;
    }
};