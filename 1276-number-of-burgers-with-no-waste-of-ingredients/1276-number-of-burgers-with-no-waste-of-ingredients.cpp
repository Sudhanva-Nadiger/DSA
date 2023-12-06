class Solution {
public:
    vector<int> numOfBurgers(int a, int b) {
        if(a&1 || a/2-b < 0 || 2*b-a/2 < 0) return {};
        
        return {a/2-b, 2*b-a/2};
    }
};