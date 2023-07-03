class Solution {
public:
    int strStr(string haystack, string needle) {
        int k = needle.size();
        
        string temp = haystack.substr(0, k);
        
        if(needle == temp) return 0;
        
        int ans = 1;
        for(int i = k; i < haystack.size(); i++) {
            temp = temp.substr(1);
            temp.push_back(haystack[i]);
            
            if(temp == needle) {
                return ans;
            }
            
            ans++;
        }
        
        return -1;
    }
};