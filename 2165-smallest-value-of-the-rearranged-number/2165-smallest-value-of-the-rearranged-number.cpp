class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num);
        bool isNeg = s[0] == '-';
        
        if(isNeg) {
            s = s.substr(1);
            sort(s.rbegin(), s.rend());
            return -1ll*stoll(s);
        }
        
        sort(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '0') {
                swap(s[i], s[0]);
                break;
            }
        }
        
        return stoll(s);
    }
};