class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int target) {
        set<int> st;
        for(int i = 0; i <= 10001; i++) {
            st.insert(i);
        }
        
        vector<vector<int>> arr;
        for(int i = 0; i < times.size(); i++) {
            arr.push_back({times[i][0], +1, i});
            arr.push_back({times[i][1], -1, i});
        }
        
        sort(begin(arr), end(arr), [](auto a, auto b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            
            return a[0] < b[0];
        });
        
        unordered_map<int, int> mp;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i][1] == 1) {
                if(arr[i][2] == target) {
                    return *st.begin();
                }
                
                mp[arr[i][2]] = *st.begin();
                st.erase(st.begin());
            }else {
                int chair = mp[arr[i][2]];
                st.insert(chair);
            }
        }
        
        return -1;
    }
};