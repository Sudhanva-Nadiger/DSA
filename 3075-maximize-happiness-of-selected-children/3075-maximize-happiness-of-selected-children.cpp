class Solution {
public:
    #define ll long long
    
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll ans = 0ll;
        sort(happiness.rbegin(), happiness.rend());
        for(int i = 0; i < happiness.size() && k > 0; i++) {
            ans += (ll)max(happiness[i]-i, 0);
            k--;
        }
        return ans;
    }
};