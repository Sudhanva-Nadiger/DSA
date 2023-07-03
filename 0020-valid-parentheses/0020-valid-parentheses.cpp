class Solution {
public:
    bool isValid(string s) {
        stack<char> t; // stack for storing opening parentheses
        // int i; // variable i to travel
        
        for(auto i:s) // travel into whole string
        {
            // if any opening parentheses, push into stack
            if(i == '(' || i =='{' || i == '[')
            {
                t.push(i);
            }
            else
            {
                // check condition for false
                if(t.empty() || (t.top() == '(' && i != ')') || (t.top() == '{' && i != '}') || (t.top() == '[' && i != ']'))
                {
                    return false;
                }
                
                t.pop(); // else pop from stack
            }
        }
        
        return t.empty();}
};