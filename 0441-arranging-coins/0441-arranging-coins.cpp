class Solution {
public:
    int arrangeCoins(int n, int row = 0) {
        if(n == 0) return row;
        
        if(n < row+1) return row;
        
        return arrangeCoins(n-(row+1), row+1);
    }
};