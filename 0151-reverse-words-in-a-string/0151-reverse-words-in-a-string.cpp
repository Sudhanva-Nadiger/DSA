class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        
        string ans = "";
        while(!ss.eof()) {
            getline(ss, word, ' ');
            if(word != "")
                ans = word + ' ' +  ans;
        }
        
        ans.pop_back();
        return ans;
    }
};