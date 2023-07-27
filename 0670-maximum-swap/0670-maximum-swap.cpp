class Solution {
public:
    int maximumSwap(int num) {
        string maxi = to_string(num);
        int n = maxi.size();
        int ans = num;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                swap(maxi[i], maxi[j]);
                ans = max(ans, stoi(maxi));
                swap(maxi[i], maxi[j]);
            }
        }
        
        return ans;
    }
};