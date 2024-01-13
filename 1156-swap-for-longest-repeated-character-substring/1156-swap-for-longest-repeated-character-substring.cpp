class Solution {
public:
    int maxRepOpt1(string s) {
        vector<pair<char, int>> arr;
        int n = s.size();
        map<char, int> mp;
        
        for(int i = 0; i < n;) {
            int j = i;
            while(j < n && s[i] == s[j]) {
                j++;
            }
            
            mp[s[i]]++;
            arr.push_back({s[i], j-i});
            i = j;
        }
        
        int ans = 0;
        n = arr.size();
        for(int i = 0; i < n; i++) {
            auto [ch, cnt] = arr[i];
            ans = max(ans, cnt);
            if(mp[ch] > 1) {
                ans = max(ans, cnt+1);
            }
            
            if(i+2 < n && arr[i+1].second == 1 && ch == arr[i+2].first) {
                cnt = arr[i+2].second + cnt;
                ans = max(ans, cnt);
                
                if(mp[ch] > 2) {
                    ans = max(ans, cnt+1);
                }
            }
        }
        
        return ans;
    }
};