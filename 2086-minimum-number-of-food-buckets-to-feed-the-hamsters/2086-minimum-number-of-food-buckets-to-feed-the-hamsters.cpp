class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        vector<int> vis(n);
        int ans = 0;
        
        for(int i = 0; i < n;) {
            if(s[i] != '.') {
                if(i+1 < n && s[i+1] == '.') {
                    vis[i+1] = 1;
                    ans++;
                    
                    i += 3;
                } else if(i-1>= 0) {
                    if(s[i-1] == '.') {
                        if(!vis[i-1]) ans++;
                        vis[i-1] = 1;
                        i++;
                    } else {
                        ans = -1;
                        break;
                    }
                } else {
                    ans = -1;
                    break;
                }
            } else {
                i++;
            }
        }
        
        return ans;
    }
};