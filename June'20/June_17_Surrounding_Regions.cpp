class Solution {
public:
    void fillWithP(vector<vector<char>> &board, int r, int c){
        
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == 'P') 
            return;
        
        board[r][c] = 'P';
        fillWithP(board, r+1, c);
        fillWithP(board, r, c+1);
        fillWithP(board, r-1, c);
        fillWithP(board, r, c-1);
    }
    
    void solve(vector<vector<char>>& board) {
        
        if(board.size() == 0) 
            return;
        
        for(int col = 0; col < board[0].size(); col++){
            
            if(board[0][col] == 'O') 
                fillWithP(board, 0, col);
            
            if(board[board.size()-1][col] == 'O') 
                fillWithP(board, board.size()-1, col); 
        }
        
        for(int row = 0; row<board.size(); row++)
        {
            if(board[row][0] == 'O') 
                fillWithP(board, row, 0); 
            if(board[row][board[0].size()-1] == 'O') 
                fillWithP(board, row, board[0].size()-1);
        }
        
        for(int r = 0; r < board.size(); r++)
        {
            for(int c = 0; c < board[0].size(); c++)
            {
                if(board[r][c] == 'O') 
                    board[r][c] = 'X';
                else if(board[r][c] == 'P') 
                    board[r][c] = 'O';
            }
        }
    }
};
