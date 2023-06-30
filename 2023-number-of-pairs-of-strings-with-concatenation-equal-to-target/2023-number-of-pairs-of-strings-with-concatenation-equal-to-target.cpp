class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> st;
        for(auto it : nums) {
            st[it]++;
        }
        
        int ans = 0;
        
        for(auto it : nums) {
            int size = it.size();
            
            if(target.substr(0, size) == it) {
                string right = target.substr(size);
                ans += st[right];
                if(it == right) {
                    ans -= 1;
                }
            }
        }
        
        return ans;
    }
};