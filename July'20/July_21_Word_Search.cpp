class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, int row, int col, int num_find, string word)
    {
        if(num_find==word.size())
            return true;
        
        if(row<0 || row>=board.size() || col<0 || col>=board[row].size()||board[row][col]!=word[num_find])
        {
            return false;
        }
        
        
        char temp = board[row][col];
        board[row][col] = ' ';
        
        bool flag = dfs(board,row+1,col,num_find+1,word)
                ||dfs(board,row,col+1,num_find+1,word)
                ||dfs(board,row,col-1,num_find+1,word)
                ||dfs(board,row-1,col,num_find+1,word);
            
        board[row][col] = temp;
        
        return flag;
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0 ; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(board,i,j,0,word))
                        return true;
                }   
            }
        }
        
        return false;
    }
};
