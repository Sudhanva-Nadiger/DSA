class Solution {
public:
    int addRungs(vector<int>& arr, int dist) {
        int n = arr.size();
        
        int ans = 0;
        int prev = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i]-prev > dist) {
                ans += (arr[i]-prev-1)/dist;
            }
            
            prev = arr[i];
        }
        
        return ans;
    }
};