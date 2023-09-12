class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        for(int i = 0;i<s.size();++i){
            v[s[i]-'a']++;
        }
        
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i = 24;i>=0;i--){
            if(v[i]==0){
                break;
            }
            
            if(v[i]>=v[i+1]){
                int prev = v[i];
                v[i] = max(0,v[i+1]-1);
                ans += prev - v[i];
            }
            
        }
        
        return ans;
        
    }
};