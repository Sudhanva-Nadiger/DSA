class Solution {
public:
    int getFrequency(string& s) {
        int n = s.size();
        
        char ch = s[0];
        for(int i = 1; i < n; i++) {
            ch = min(ch, s[i]);
        }
        
        int count = 0;
        for(auto it : s) {
            count += (it == ch);
        }
        
        return count;
    }
    
    int binarySearch(vector<int>& nums, int target) {
        int index = -1;
        
        int i = 0, j = nums.size()-1;
        
        while(i <= j) {
            int mid = (i+j)/2;
            
            if(nums[mid] <= target) {
                i = mid+1;
            } else {
                index = mid;
                j = mid-1;
            }
        }
        
        return (index == -1 ? 0 : nums.size()-index);
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> nums;
        
        for(string& word: words) {
            nums.push_back(getFrequency(word));
        }
        
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int frq = getFrequency(queries[i]);
            int count = binarySearch(nums, frq);
            ans.push_back(count);
        }
        
        return ans;
    }
};