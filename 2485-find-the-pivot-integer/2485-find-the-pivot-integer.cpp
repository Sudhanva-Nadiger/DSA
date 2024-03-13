class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int temp = 0;
        for(int pivot = 1; pivot <= n; pivot++){
            temp += pivot;
            sum -= (pivot-1);
            if(sum == temp){
                return pivot;
            }
        }
        
        return -1;
        
    }
};