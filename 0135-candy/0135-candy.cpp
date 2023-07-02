class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<pair<int,int>> arr;
        for(int i = 0; i < ratings.size(); i++) {
            arr.push_back({ratings[i], i});
        }
        
        sort(begin(arr), end(arr));
        vector<int> count(arr.size(), 1);
        
        for(int i = 0; i < arr.size(); i++) {
            int index = arr[i].second;
            
            if(index > 0 && ratings[index-1] < ratings[index]) {
                if(count[index] <= count[index-1]) {
                    count[index] = count[index-1]+1;
                }
            }
            
            if(index < arr.size()-1 && ratings[index+1] < ratings[index]) {
                if(count[index] <= count[index+1]) {
                    count[index] = count[index+1]+1;
                }
            }
        }
        
        return accumulate(begin(count), end(count), 0);
    }
};