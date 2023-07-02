class Solution {
public:
    long long merge(vector<int>& nums, int start, int mid, int end, int diff) {
        vector<int> tot(end-start+1);
        long long count = 0;
        
        for(int i = start, j = mid+1; i <= mid && j <= end;) {
            if(nums[i] <= nums[j]+diff) {
                count += (long long)(end-j+1);
                i++;
            }else {
                j++;
            }
        }
        
        int k = 0, i, j;
        
        for(i = start, j = mid+1;i <= mid && j <= end;) {
            if(nums[i] <= nums[j]) {
                tot[k++] = nums[i++];
            }else {
                tot[k++] = nums[j++];
            }
        }
        
        while(i <= mid) {
            tot[k++] = nums[i++];
        }
        while(j <= end) {
            tot[k++] = nums[j++];
        }
        
        for(auto it : tot) {
            nums[start++] = it;
        }
        
        return count;
    }
    
    long long mergeSort(vector<int>& nums, int start, int end, int diff) {
        if(start == end) {
            return 0;
        }
        
        long long ans = 0;
        int mid = (start+end)/2;
        
        ans += mergeSort(nums, start, mid, diff);
        ans += mergeSort(nums, mid+1, end, diff);
        
        ans += merge(nums, start, mid, end, diff);
        
        return ans;
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> arr(n);
        
        for(int i = 0;i < n; i++) {
            arr[i] = nums1[i]-nums2[i];
        }
        
        return mergeSort(arr, 0, n-1, diff);
    }
};