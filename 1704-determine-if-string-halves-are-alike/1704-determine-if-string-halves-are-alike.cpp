class Solution {
public:
    unordered_set<char> st;
    
    bool isVowel(char c){
        if(st.find(c) != st.end()){
            return true;
        }
        
        return false;
    }
    
    bool halvesAreAlike(string s) {
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        
        int numberOfVowels = 0;
        
        for(char c : s){
            if(isVowel(c)){
                numberOfVowels++;
            }
        }
        
        if(numberOfVowels&1){
            return false;
        }
        int numberOfVowelsInHalf = 0;
        for(int i= 0;i < s.size()/2; i++){
            if(isVowel(s[i])){
                numberOfVowelsInHalf++;
            }
        }
        
        return numberOfVowelsInHalf == numberOfVowels/2;
    }
};