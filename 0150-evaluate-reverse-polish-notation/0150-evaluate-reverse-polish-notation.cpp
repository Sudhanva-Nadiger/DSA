class Solution {
public:
    vector<string> operators = {"+","-","*","/"};
    bool isOperator(string& s){
        
        for(auto c : operators){
            if(c == s){
                return true;
            }
        }
        
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<long long int> st;
        
        for(int i = 0; i < tokens.size(); i++){
            if(isOperator(tokens[i])){
                int a = (st.top());st.pop();
                int b = (st.top());st.pop();
                
                auto op = tokens[i];
                if(op == "+"){
                    st.push(a+b);
                }
                else if(op == "-"){
                    st.push(b-a);
                }else if(op == "*"){
                    st.push((long long int)a*b);
                }else{
                    st.push(b/a);
                }
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};