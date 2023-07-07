class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        nums.push_back((int)-1e5);
        deque<int> q;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i-k >= 0) {
                ans.push_back(nums[q.front()]);
            }
            
            while(q.size() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            
            while(q.size() && q.front() <= i-k) {
                q.pop_front();
            }
            
            q.push_back(i);
        }
        
        return ans;
    }
};