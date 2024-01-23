class Solution {
public:
    int f(vector<string>& arr, int index, vector<int>& visited) {
        if(index == arr.size()) {
            return 0;
        }
        
        int ans = 0;
        for(int i = index; i < arr.size(); i++) {
            bool ok = true;
            
            for(auto c : arr[i]) {
                if(visited[c-'a']) {
                    ok = false;
                    break;
                }
            }
            
            if(ok) {
                for(auto c: arr[i])
                    visited[c-'a'] = 1;
                int t = arr[i].size() + f(arr, i+1, visited);
                ans = max(ans, t);
                for(auto c: arr[i]) {
                    visited[c-'a'] = 0;
                }
            }
        }
        
        int t = f(arr, index+1, visited);
        ans = max(ans, t);
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> vis(26);
        vector<string> nums;
        for(auto it : arr) {
            unordered_set<char> st(it.begin(), it.end());
            if(st.size() == it.size()) {
                nums.push_back(it);
            }
        }
        return f(nums, 0, vis);
    }
};