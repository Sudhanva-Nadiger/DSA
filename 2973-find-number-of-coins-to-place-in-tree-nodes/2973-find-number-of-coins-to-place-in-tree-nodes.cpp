class Solution {
public:
    #define ll long long
    vector<ll> ret;
    
    void populate(multiset<int>& a, multiset<int>& b) {
        for(auto it : b) {
            a.insert(it);
        }
    }
    
    void handleMax(multiset<int>& a, multiset<int>& b) {
        multiset<int> ans;
        populate(ans, a);
        populate(ans, b);
        
        while(ans.size() > 3) {
            ans.erase(ans.begin());
        }
        
        a = ans;
    }
    
    void handleMin(multiset<int>& a, multiset<int>& b) {
        multiset<int> ans;
        populate(ans, a);
        populate(ans, b);
        
        while(ans.size() > 2) {
            ans.erase(ans.find(*ans.rbegin()));
        }
        
        a = ans;
    }
    
    ll computeCoin(multiset<int>& a, multiset<int>& b) {
        ll min1 = *b.begin(), min2 = *b.rbegin();
        ll max1 = *a.begin(), max2 = *prev(a.rbegin()), max3 = *a.rbegin();
        
        return max({max1*max2*max3, min1*min2*max3, 0ll});
    }
    
    void addTomax(multiset<int>& a, int cost) {
        a.insert(cost);
        
        while(a.size() > 3) {
            a.erase(a.begin());
        }
    }
    
    void addTomin(multiset<int>& a, int cost) {
        a.insert(cost);
        
        while(a.size() > 2) {
            a.erase(a.find(*a.rbegin()));
        }
    }
    
    pair<int, pair<multiset<int>,multiset<int>>> dfs(vector<vector<int>>& adj, int node, int par, vector<int>& cost) {
        int total = 1;
        multiset<int> mini;
        multiset<int> maxi;
        
        for(auto it : adj[node]) {
            if(it == par) continue;
            
            auto [count, sets] = dfs(adj, it, node, cost);
            auto [maxSet, minSet] = sets;
            
            total += count;
            
            handleMax(maxi, maxSet);
            handleMin(mini, minSet);
        }
        
        addTomax(maxi, cost[node]);
        addTomin(mini, cost[node]);
        
        if(total < 3) {
            ret[node] = 1;
        } else {
            auto coin = computeCoin(maxi, mini);
        
            ret[node] = coin;
        }
        
        return {total, {maxi, mini}};
    }
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        ret = vector<ll>(n);
        vector<vector<int>> adj(n);
        
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(adj, 0, -1, cost);
        
        return ret;
    }
};