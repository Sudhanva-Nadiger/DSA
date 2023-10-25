class Solution {
public:
    int solve(int n,int k){
        if(n == 1){
            return 0;
        }
        
        if(k == 1){
            return 0;
        }
        
        
        int prevElement = solve(n-1,(k+1)/2);
        
        if(prevElement == 1){
            if(k%2 ==0){
                return 0;
            }
            
            return 1;
        }
         if(k%2 == 0){
             return 1;
         }
        
        return 0;
        
    }
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};