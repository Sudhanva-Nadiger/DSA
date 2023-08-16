class Solution {
public:
    bool f(vector<int>& A, vector<int>& B, int k, long long budget) {
        deque<int> dq;
        long long sum = 0ll;
        
        for(int i = 0; i < A.size(); i++) {
            while(dq.size() && A[dq.back()] < A[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            while(dq.size() && dq.front() <= i-k) {
                dq.pop_front();
            }
            
            if(i-k >= 0) {
                sum -= B[i-k];
            }
            
            sum += B[i];
            
            if(i-k >= -1) {
                long long tot = A[dq.front()] + k*(sum);
                if(tot <= budget) return true;
            }
        }
        
        return false;
    }
    
    int maximumRobots(vector<int>& A, vector<int>& B, long long budget) {
        int n = A.size();
        int l = 1, r = n;
        int ans = 0;
        
        while(l <= r) {
            int mid = (l+r)/2;
            if(f(A, B, mid, budget)) {
                ans = mid;
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
        
        return ans;
    }
};