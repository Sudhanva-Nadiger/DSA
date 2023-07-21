class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> arr(n);
        
        for(auto it : bookings) {
            int l = it[0];
            int r = it[1];
            int s = it[2];
            
            arr[l-1] += s;
            if(r < n)
                arr[r] -= s;
        }
        
        for(int i = 1; i < n; i++) {
            arr[i] += arr[i-1];
        }
        
        return arr;
    }
};