class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<vector<int>> nums(n, vector<int> (2, 0));
        
        int y = 0, c = 0;
        
        for(int i = n-1; i >= 0; i--) {
            y += s[i]=='Y';
            c += s[i]=='N';
            
            nums[i][0] = y;
            nums[i][1] = c;
        }
        
        int minPenalty = 1e9;
        int day = 0;
        for(int i = 0; i < n; i++) {
            int penalty = nums[i][0] + (c - nums[i][1]);
            if(penalty < minPenalty) {
                minPenalty = penalty;
                day = i;
            }
        }
        
        if(c < minPenalty) {
            day = n;
        }
        
        return day;
    }
};