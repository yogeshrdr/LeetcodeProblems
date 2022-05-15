class Solution {
public:
    
    int getLiveNeigh(vector<vector<int>> board, int i, int j) {
        int count = 0;
        int m =  board.size();
	    int n =  board[0].size();
        
        if(i > 0 &&  board[i-1][j] == 1)
            count++;
        
        if(i < m-1 &&  board[i+1][j] == 1)
                count++;
                 
        if(j > 0 &&  board[i][j-1] == 1) 
            count++;
        
        if(j < n-1 &&  board[i][j+1] == 1)
            count++;
        
        if(i > 0 && j > 0 &&  board[i-1][j-1] == 1) 
            count++;
        
        if(i < m-1 && j < n-1 &&  board[i+1][j+1] == 1)
            count++;
        
        if(i < m-1 && j > 0 &&  board[i+1][j-1] == 1)
            count++;
        
        if(i > 0 && j < n-1 &&  board[i-1][j+1] == 1)
            count++;
        
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        
        
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                
                int n= getLiveNeigh(temp, i, j);
                
                if(board[i][j] == 0 && n==3) 
                    board[i][j] = 1;
                
                if(board[i][j] == 1 && n!=3 && n!=2)
                    board[i][j] = 0;
                
            }
        }
        
    }
};