class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
    
        vector<double> arr;
        
        for(int i =0; i < n; i++) {
            arr.push_back((double)dist[i]/(double)speed[i]);
        }
        
        sort(begin(arr), end(arr));
        
        int ans = 1;
        int time = 0;
        
        for(int i = 1; i <n; i++) {
            if(arr[i] - time > 1) {
                ans++;
                time++;
            }else {
                break;
            }
        }
        
        return ans;
    }
};