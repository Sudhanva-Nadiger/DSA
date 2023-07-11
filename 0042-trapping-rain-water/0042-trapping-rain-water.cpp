class Solution {
public:
    int trap(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            while(st.size() && nums[st.top()] < nums[i]) {
                int id = st.top();
                int poppedHeight = nums[id];
                st.pop();
                if(st.size()) {
                    int h = min(nums[st.top()], nums[i])-poppedHeight;
                    ans += (i-st.top()-1)*h;
                }
            }
            
            st.push(i);
        }
        
        return ans;
    }
};