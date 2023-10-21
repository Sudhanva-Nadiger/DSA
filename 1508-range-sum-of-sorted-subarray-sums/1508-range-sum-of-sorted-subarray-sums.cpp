class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int m = 1e9 + 7;
        vector<long long> arr;
        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = i; j < n; j++) {
                sum += (long long)nums[j];
                sum %= m;
                arr.push_back(sum%m);
            }
        }
        left--;
        sort(begin(arr), end(arr));
        long long sum = 0ll;
        for(int i = left; i < right; i++){
            sum = (sum + arr[i])%m;
        }
        return sum;
    }
};