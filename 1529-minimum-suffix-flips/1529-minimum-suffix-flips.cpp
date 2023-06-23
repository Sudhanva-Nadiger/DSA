class Solution {
public:
    int minFlips(string target) {
        int flip = 0;
        
        for(auto c : target) {
            if(c == '1' && flip%2 == 0) {
                flip++;
            }else if(c == '0' && flip%2 == 1) {
                flip++;
            }
        }
        return flip;
    }
};