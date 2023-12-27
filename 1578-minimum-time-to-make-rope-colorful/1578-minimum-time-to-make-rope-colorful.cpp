class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size();
        for(int i = 0; i < n;) {
            int j = i;
            int sum = 0, maxi = 0;
            while(j < n && (colors[j] == colors[i])) {
                sum += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }
            
            sum -= maxi;
            ans += sum;
            i = j;
        }
        
        return ans;
    }
};