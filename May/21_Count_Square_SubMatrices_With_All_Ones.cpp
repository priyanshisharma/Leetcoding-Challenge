// Following happens to be my first approach, finding bigger squares from smaller ones

class Solution {
public:
    int ctr = 0;
    void bigger_squares(vector<vector<int>>& matrix, int r, int c, int l)
    {
        if(c+l>=matrix[0].size()||r+l>=matrix.size())
            return;
        
        int col = c + l ;
        for(int i = r ; i<=r+l ; i++)
        {
            if(matrix[i][col]==0)
                    return;
        }  
        
        int row = r + l ;
        for(int i = c ; i<=c+l ; i++)
        {
            if(matrix[row][i]==0)
                    return;
        }
        
        ctr++;
        bigger_squares(matrix,  r, c, l+1);
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                   if(matrix[i][j]==1)
                   {
                       ctr++;
                       bigger_squares(matrix,i,j,1);
                   }
            }
        }
        return ctr;
    }
};
