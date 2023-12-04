class Solution {
public:
    bool okay(string s){
        if(s[0] == s[1] and s[1] == s[2])
            return 1;
        return 0;
    }
    string largestGoodInteger(string nums) {
        string ans ;
        for(int i = 0;i<3;++i){
            ans += nums[i];
        }
        string temp = "-1";
        if(okay(ans)){
            temp = ans;
        }
        for(int i = 3;i<nums.size();++i){
            ans.erase(ans.begin());
            ans += nums[i];
            if(okay(ans)){
                int x = stoi(ans);
                int y = stoi(temp);
                if(x>y){
                    temp = ans;
                }
            }
            
        }
        if(temp == "-1"){
            return "";
        }
        return temp;
    }
};