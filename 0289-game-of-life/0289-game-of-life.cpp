class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dx[8]={1, -1, 1, -1, 0, 0, 1, -1}, 
            dy[8]={0, 0, 1, -1, -1, 1, -1, 1};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                
                for(int k = 0; k < 8; k++) {
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    
                    if(0<=ni && 0<=nj && ni < m && nj < n) {
                        count += ((board[ni][nj]==1) || (board[ni][nj] == -1));
                    }
                }        
                
                if(board[i][j] == 1) {
                    if(count < 2) {
                        board[i][j] = -1;
                    }else if(count > 3) {
                        board[i][j] = -1;
                    }
                }else if(board[i][j] == 0) {
                    if(count == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        
        for(int i = 0;i < m; i++) {
            for(int j = 0;j < n; j++) {
                if(board[i][j] == -1) {
                    board[i][j] = 0;
                }else if(board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};