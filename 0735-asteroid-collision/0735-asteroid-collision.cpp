class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                int count = 0;
                while(st.size() && st.top() > 0) {
                    if(st.top() > abs(nums[i])) {
                        count++;
                        break;
                    }else if(st.top() == abs(nums[i])) {
                        st.pop();
                        count++;
                        break;
                    }else{
                        st.pop();
                    }
                }
                
                if(!count) st.push(nums[i]);
            }else {
                st.push(nums[i]);
            }
        }
        
        vector<int> ans;
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};