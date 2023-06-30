class FindSumPairs {
public:
    unordered_map<int,int> mp1, mp2;
    vector<int> t;
    void f(vector<int>& nums, unordered_map<int,int>& mp) {
        for(auto it : nums) {
            mp[it]++;
        }
    }
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        f(nums1, mp1);
        f(nums2, mp2);
    
        t = nums2;
    }
    
    void add(int index, int val) {
        
        int prevVal = t[index];
        t[index] += val;
        
        mp2[prevVal]--;
        mp2[t[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        if(mp1.size() > mp2.size()) {
            for(auto it : mp2) {
                if(mp1.count(tot-it.first)) {
                    ans += (it.second*mp1[tot-it.first]);
                }
            }
        }else {
            for(auto it : mp1) {
                if(mp2.count(tot-it.first)) {
                    ans += (it.second*mp2[tot-it.first]);
                }
            }
        }
        
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */