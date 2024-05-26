class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans = "";
        
        for(int i = 0; i < n; ) {
            char c = word[i];
            int j = i;
            
            while(j < n && (j-i+1) <= 9 && word[j] == c) {
                j++;
            }
            
            ans += to_string(j-i);
            ans.push_back(c);
            
            i = j;
        }
        
        return ans;
    }
};