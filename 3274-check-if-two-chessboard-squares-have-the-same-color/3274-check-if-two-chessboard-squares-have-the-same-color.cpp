class Solution {
public:
    bool f(string s) {
        return (s[0]-'a'+1)%2 == (s[1]-'0')%2;
    }
    bool checkTwoChessboards(string a, string b) {
       return f(a) == f(b);
    }
};