class Solution {
public:
    int maxArea(vector<int>& height){
        stack<int> st;
        height.push_back(0);
        int ans = 0;
        for(int i = 0;i<height.size();i++){
            while(st.size() and height[st.top()]>height[i]){
                int currIndex = st.top();
                st.pop();
                int poppedHeight = height[currIndex];
                if(st.size() == 0){
                    ans = max(ans,i*poppedHeight);
                }
                else{
                    int dist = i-st.top()-1;
                    ans = max(ans,poppedHeight*dist);
                }
            }
            st.push(i);
        }
        height.pop_back();
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int> height(matrix[0].size());
        
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(i == 0){
                    height[j] = matrix[i][j]-'0';
                }
                else{
                    if(matrix[i][j] == '0'){
                        height[j] = 0;
                    }
                    else{
                        height[j] = height[j]+1;
                    }
                }
            }
            
            int area = maxArea(height);
            ans = max(ans,area);
        }
        return ans;
    }
};