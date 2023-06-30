class Solution {
public:
    int getLeft(vector<int>& nums, int left, int right, int t) {
        
        int ans = -1;
        
        while(left <= right) {
            int mid = (left+right)/2;
            
            if(nums[mid] < t) {
                left  = mid+1;
            }else {
                ans = mid;
                right= mid-1;
            }
        }
        
        return ans;
    }
    
    int getRight(vector<int>& nums, int left, int right, int t) {
        int ans = nums.size();
        
        while(left <= right) {
            int mid = (left+right)/2;
            
            if(nums[mid] > t) {
                right  = mid-1;
            }else {
                ans = mid;
                left= mid+1;
            }
        }
        
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        long long ans = 0ll;
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            int l = lower-nums[i];
            int r = upper-nums[i];
            
            int left = getLeft(nums, i+1, n-1, l);
            int right = getRight(nums, i+1, n-1, r);
            
            // cout <<nums[i] << " " << left << " " << right << endl; 
            
            if(left != -1 && right != n && right >= left) {
                ans += (long long)right-left+1;
            }
        }
        
        return ans;
    }
};