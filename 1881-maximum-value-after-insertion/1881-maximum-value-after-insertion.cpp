class Solution {
public:
    string maxValue(string n, int x) {
      string ch = "";
      if(n[0] == '-') {
          ch = "-";
          n = n.substr(1);
      }
       int i = 0; 
       while(i < n.size()) {
           if(n[i]-'0' < x) {
               if(ch != "-"){
                   n.insert(n.begin()+i, ('0'+x));
                    break;
               }
           }else if(n[i]-'0' > x){
               if(ch == "-") {
                   n.insert(n.begin()+i, ('0'+x));
                    break;
               }
           }
           i++;
       }

       if(i == n.size()) {
           n.push_back((x+'0'));
       }
        
        return ch + n;
    }
};