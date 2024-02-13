class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto s : words){
            int i;
            for(i = 0;i<s.size()/2;i++){
                if(s[i] != s[s.size()-i-1]){
                    break;
                }
            }
            
            if(i == s.size()/2){
                return s;
            }
        }
        
        return "";
    }
};