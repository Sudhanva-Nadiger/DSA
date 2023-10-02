class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        if(n <= 2) return false;
        
        int alice = 0, bob = 0;
        
        for(int i = 1; i+1 < n; i++) {
            if(colors[i-1] == colors[i] && colors[i] == colors[i+1]) {
                if(colors[i] == 'A') {
                    alice++;
                } else {
                    bob++;
                }
            }
        }
        
        return alice > bob;
    }
};