class Solution {
public:
    vector<int> sum;
    int f(vector<int>& nums, int index, int k) {
        if(index == nums.size()) {
            return *max_element(begin(sum), end(sum));
        }
        
        int ans = 1e9;
        
        for(int kid = 0; kid< k; kid++) {
            sum[kid] += nums[index];
            int t = f(nums, index+1, k);
            sum[kid] -= nums[index];
            ans = min(ans, t);   
        }
        
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        sum = vector<int>(k);
        return f(cookies, 0, k);
    }
};