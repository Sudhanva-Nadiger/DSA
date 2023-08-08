class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long s = 0;
        
        for(int i = 0; i < n; i++) {
            s += (long long)abs(nums1[i]-nums2[i]);
        }
        
        // cout << s << endl;
        
        int mod = 1e9+7;
        long long ans = s;
        
        vector<int> arr = nums1;
        sort(begin(arr), end(arr));
        
        for(int i = 0; i < n; i++) {
            int target = nums2[i];
            
            int l = 0, r = n-1;
            int res = 0;
            int diff = INT_MAX;
            
            while(l <= r) {
                int mid = (l+r)/2;
                int d = abs(arr[mid]-target);
                if(d < diff) {
                    res = arr[mid];
                    diff = d;
                }
                
                if(arr[mid] > target) {
                    r = mid-1;
                }else {
                    l = mid+1;
                }
            }
            
            long long t = s - abs(nums1[i]-nums2[i]);
            t = (t + abs(res-nums2[i]));
            // cout << t << endl;
            ans = min(ans, t);
        }
        
        return ans%mod;
    }
};