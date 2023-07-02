class Solution {
public:
    int merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> tot(end-start+1);
        
        int count = 0;
        
        for(int i = start, j = mid+1; i <= mid && j <= end;) {
            if(nums[i] > (long long)2*nums[j]) {
                count += (mid-i+1); 
                j++;
            }else {
                i++;
            }
        }
        
        int k = 0, i, j;
        
        for(i = start, j = mid+1; i <= mid && j <= end;) {
            
            if(nums[i] <= nums[j]) {
                tot[k] = nums[i];
                i++;
                k++;
            }else {
                tot[k] = nums[j];
                j++;
                k++;
            }
        }
        
        while(i <= mid) {
            tot[k++] = nums[i++];
        }
        
        while(j <= end) {
            tot[k++] = nums[j++];
        }
        
        for(int it : tot) {
            nums[start++] = it;    
        }
        
        return count;
    }
    int mergeSort(vector<int>& nums, int start, int end) {
        if(end == start) {
            return 0;
        }
        
        int ans = 0;
        int mid = (start+end)/2;
        ans += mergeSort(nums, start, mid);
        ans += mergeSort(nums, mid+1, end);
        
        ans += merge(nums, start, mid, end);
        
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int ans = mergeSort(nums, 0, nums.size()-1);
        return max(0, ans);
    }
};