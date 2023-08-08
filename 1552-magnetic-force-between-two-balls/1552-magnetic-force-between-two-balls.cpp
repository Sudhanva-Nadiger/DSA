class Solution {
public:
    int f(vector<int>& nums, int m, int mid) {
        int totBalls = 1;
        int curr = 0;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i]-nums[curr] >= mid) {
                totBalls ++;
                curr = i;
            }
        }
        
        return totBalls >= m;
    }
   
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        long long l = 0, r = 1e14+1;
        long long ans = 0;
        
        sort(begin(position), end(position));
        
        while(l <= r) {
            long long mid = l + (r-l)/2;
            
            if(f(position,  m, mid)) {
                ans = mid;
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
        
        return ans;
    }
};