class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int zor = derived[0];
        
        for(int i = 1; i < derived.size(); i++) {
            zor ^= derived[i];
        }
        
        return !zor;
    }
};