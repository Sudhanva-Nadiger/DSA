class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size()-1;
        
        while(left <= right) {
            int mid = (left+right)/2;
            
            if(letters[mid] <= target) {
                left = mid+1;
            }else {
                right = mid-1;
            }
        }
        
        return letters[left%letters.size()];
    }
};