class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int maxi = *max_element(nums1.begin(), nums1.end());
        vector<long long> arr(maxi+1);
        for(auto it : nums1) {
            arr[it]++;
        }
        map<long long, long long> mp;
        for(auto it : nums2) {
            mp[it]++;
        }
        
        long long ans = 0ll;
        
        for(auto it : mp) {
            long long t = it.first*k;
            long long temp = t;
            long long res = 0ll;
            
            while(t < arr.size()) {
                res += arr[t];
                t += temp;
            }
            
            ans += res*it.second;
        }
        
        return ans;
    }
};