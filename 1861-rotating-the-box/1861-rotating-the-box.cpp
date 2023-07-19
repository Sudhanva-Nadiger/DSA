class Solution {
public:
    void moveStone(vector<vector<char>>& box, int row, int col) {
        int originalCol = col;
        
        col += 1;
        int count = 0;
        
        while(col < box[0].size() && box[row][col] == '.') {
            count++;
            col++;
        }
        
        if(count > 0) {
            box[row][originalCol] = '.';
            box[row][originalCol+count] = '#';
        }
    }
    
    vector<vector<char>> rotateImage(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> ans;
        int id = 0;
        
        for(int j = 0; j < n; j++) {
            vector<char> temp;
            for(int i = 0; i < m; i++) {
                temp.push_back(box[i][j]);
            }
            
            reverse(begin(temp), end(temp));
            ans.push_back(temp);
        }
        
        return ans;
    }
    
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        
        for(int i = 0; i < m; i++) {
            for(int j = n-1; j >= 0; j--) {
                if(box[i][j] == '#') {
                    moveStone(box, i, j);
                }
            }
        }
        
        return rotateImage(box);
    }
};