class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        if(grid.size()==0)
            return 0;
        
        int res=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
            {
                
                if(grid[i][j]==1)
                {
                    if(i>0)
                    {
                       if(grid[i-1][j] == 0)
                           res++;
                    }
                    else
                        res++;

                    if(i<grid.size()-1)
                    {
                         if(grid[i+1][j] == 0)
                           res++;
                    }
                    else
                        res++;

                    if(j>0)
                    {
                        if(grid[i][j-1] == 0)
                           res++;
                    }
                    else
                        res++;

                    if(j<grid[i].size()-1)
                    {
                        if(grid[i][j+1] == 0)
                           res++;
                    }
                    else
                        res++;
                
                }
                    
            }
                     
        }
        
        return res;
    }
};
