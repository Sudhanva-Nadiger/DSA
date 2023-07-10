class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i = 1; i <= n; i++) {
            int num = i;
            int count = 0;
            while(num > 0) {
                count++;
                num -= (num&(-num));
            }
            ans[i] = count;
        }
        
        return ans;
    }
};