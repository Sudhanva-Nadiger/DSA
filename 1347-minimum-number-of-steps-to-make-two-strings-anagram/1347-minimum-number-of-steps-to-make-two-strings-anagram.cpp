class Solution {
public:
    void f(string& s, vector<int>& arr) {
        arr.resize(26, 0);
        for(auto it : s) {
            arr[it-'a']++;
        }
    }
        
    int minSteps(string s, string t) {
        vector<int> arr1, arr2;
        f(s, arr1);
        f(t, arr2);
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(arr1[i] > arr2[i]) {
                ans += arr1[i]-arr2[i];
            }
        }
        
        return ans;
    }
};