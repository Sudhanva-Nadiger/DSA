class Solution {
public:
    string maximumOddBinaryNumber(string s) {
         string t = "";
            int cnt = 0;
            for(int i=0; i<s.length(); i++){
                if(s[i] == '1') cnt++;
            }
            for(int i=0; i<s.length()-1; i++){
                if(cnt>1){
                    t += '1';
                    cnt--;
                }
                else t += '0';
            }
            t += '1';
            return t;
    }
};