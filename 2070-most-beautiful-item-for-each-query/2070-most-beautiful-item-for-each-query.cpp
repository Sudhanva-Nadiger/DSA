class Solution {
public:
    int bs(vector<vector<int>>& nums, int n, int target) {
        int l = 0, r = n-1;
        int ans = -1;
        
        while(l <= r) {
            int mid = (l+r)/2;
            
            if(nums[mid][0] <= target) {
                // cout << mid << " mid" << endl;
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return ans;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(begin(items), end(items), [](auto a, auto b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            
            return a[0] < b[0];
        });
        
        // for(auto it : items) {
        //     cout << it[0] << " " << it[1] << endl;
        // }
        
        vector<int> arr(n);
        
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, items[i][1]);
            arr[i] = maxi;
        }
        
        vector<int> ans;
        for(auto it : queries) {
            int index = bs(items, n, it);
            // cout << it << " " << index << endl;
            if(index != -1)
                ans.push_back(arr[index]);
            else ans.push_back(0);
        }
        
        return ans;
    }
};