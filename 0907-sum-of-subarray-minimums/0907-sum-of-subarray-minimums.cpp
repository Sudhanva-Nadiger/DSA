class Solution {
public:
    int mod = 1e9+7;
    vector<int> minLeft(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        
        for(int i = 0; i < n;i++){
            while(st.size() and arr[st.top()] > arr[i]){
                st.pop();
            }
            
            if(st.size()){
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> minRight(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n,n);
        stack<int> st;
        
        for(int i = n-1; i>= 0; i--){
            while(st.size() and arr[st.top()] >=arr[i]){
                st.pop();
            }
            
            if(st.size()){
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> leftArr = minLeft(arr);
        vector<int> rightArr = minRight(arr);
        long long int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            int leftId = leftArr[i];
            int rightId = rightArr[i];
            //cout << leftId << " " << rightId << endl;
            ans = (ans+(long long)arr[i]*((i-leftId)*(rightId-i)))%mod;
        }
        
        return ans;
    }
};