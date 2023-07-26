class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        int n = nums.size();
        
        for(int i = 0;  i < n; i++) {
            nums[i].push_back(i);
        }
        
        sort(nums.begin(), nums.end());
        vector<int> res(n);
        
        for(int i = 0; i < n; i++) {
            int l = i;
            int r = n-1;
            
            int ans = -1;
            
            int end = nums[i][1];
            
            while(l <= r) {
                int mid = (l+r)/2;
                
                int start = nums[mid][0];
                if(start >= end) {
                    ans = nums[mid][2];
                    r = mid-1;
                }else {
                    l = mid+1;
                }
            }
            
            res[nums[i][2]] = ans;
        }
        
        return res;
    }
};