class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> arr;
        for(int i = 0; i < nums1.size(); i++){
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(rbegin(arr), rend(arr));
        priority_queue<int,vector<int>, greater<int>> pq;
        long long sum = 0;
        long long ans = 0;
        for(auto it:arr){
            pq.emplace(it[1]);
            sum += it[1];
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans = max(ans, sum*it[0]);
            }
        }
        return ans;
    }
};