class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        vector<vector<int>> arr;
        
        for(int i = 1; i < nums.size(); i++) {
            int prev = nums[i-1]&1;
            int curr = nums[i]&1;
            
            if(prev == curr) {
                arr.push_back({i-1, i});
            }
        }
        
        int n = q.size();
        vector<bool> ans;
        
        for(auto  it : q) {
            int i = 0, j = arr.size()-1;
            bool res = true;
            
            while(i <= j && res) {
                int mid = (i+j)/2;
                
                if(arr[mid][1] <= it[0]) {
                    i = mid + 1;
                } else if(arr[mid][0] >= it[1]) {
                    j = mid - 1;
                } else {
                    res = false;
                }
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};