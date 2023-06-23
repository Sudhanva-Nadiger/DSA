class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        
        vector<pair<int, int>> arr;
        for(int i = 0;i < nums2.size(); i++) {
            arr.push_back({nums2[i], i});
        }
        sort(arr.begin(), arr.end());
        
        int i = 0, j = 0;
        vector<int> ans(nums1.size());
        vector<int> remaining;
        while(i < nums1.size() && j < arr.size()) {
            if(nums1[i] > arr[j].first) {
                ans[arr[j].second] = nums1[i];
                j++;
            }else {
                remaining.push_back(nums1[i]);
            }
            
            i++;
        }
        
        while(j < arr.size()) {
            ans[arr[j].second] = remaining.back();
            remaining.pop_back();
            j++;
        }
        
        return ans;
    }
};