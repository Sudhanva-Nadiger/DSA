
class Solution {
public:
    static bool compare(string a,string b){
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        int count = 0;
        vector<string> v;
       for(int i : nums){
           if(i==0){
               count++;
           }
           v.emplace_back(to_string(i));
       }
        if(count == nums.size()){
            return "0";
        }
        sort(v.begin(),v.end(),compare);
        
        string ans="";
        for(int i = 0;i<nums.size();++i){
            ans += v[i];
        }
        
        return ans;
    }
};