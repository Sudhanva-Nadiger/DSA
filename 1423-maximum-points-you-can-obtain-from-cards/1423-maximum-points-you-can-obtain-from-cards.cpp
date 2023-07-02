class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int i = 0;
        int ans = 0;
        int temp = 0;
        
        while(i < k) {
            temp += nums[i];
            i++;
        }
        
        i--;
        
        int j = nums.size()-1;
        
        ans = max(ans, temp);
        // cout << temp << endl;
        while(k--) {
            temp += nums[j];
            temp -= nums[i];
            // cout << temp << endl;
            
            j--;
            i--;
            ans = max(ans, temp);
        }
        
        return ans;
    }
};