class Solution {
public:
    int getScore(string& s) {
        vector<int> arr(26, 0);
        
        for(auto it : s) {
            arr[it-'a']++;
        }
        
        int mini = 1e9, maxi = 0;
        
        for(int it : arr) {
            if(it != 0) {
                mini = min(it, mini);
                maxi = max(it, maxi);
            }
        }
        
        return maxi-mini;
    }
    int beautySum(string s) {
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++) {
            string sub = "";
            
            for(int j = i; j < s.size(); j++) {
                sub.push_back(s[j]);
                ans += getScore(sub);
            }
        }
        
        return ans;
    }
};