class Solution {
public:
    bool solve(vector<vector<char>>&board, string word, int i, int j, int k){  
        if(k == word.size()) 
            return true; 
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[k]) 
            return false;
        
        char x = board[i][j];
        
        board[i][j] = '*';
        
        bool x1 = solve(board, word, i+1, j, k+1);
        bool x2 = solve(board, word, i, j+1, k+1);
        bool x3 = solve(board, word, i-1, j, k+1); 
        bool x4 = solve(board, word, i, j-1, k+1);
     
        board[i][j] = x;
		
        return x1 || x2 || x3 || x4;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0] && solve(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};