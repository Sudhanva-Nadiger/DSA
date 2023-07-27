class Solution {
public:
    bool dfs(string& s, int i, int target, vector<vector<int>>& dp) {
        if(target < 0) return false;
        
        if(i == s.size()) {
            return target == 0;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        bool ans = false;
        string temp = "";
        
        for(int index = i; index < s.size(); index++) {
            temp.push_back(s[index]);
            int t = stoi(temp);
            ans = ans | dfs(s, index+1, target-t, dp);
        }
        
        return dp[i][target] = ans;
    }
    
    bool isValid(int num) {
        string s = to_string(num*num);
        vector<vector<int>> dp(s.size()+1, vector<int>(num+1, -1));
        return dfs(s, 0, num, dp);
    }
    
    int punishmentNumber(int n) {
        int sum = 0;
        
        for(int i = 1; i <= n; i++) {
            if(isValid(i)) {
                sum += i*i;
            }
        }
        
        return sum;
    }
};