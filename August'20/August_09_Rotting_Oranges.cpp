class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    set<pair<int,int>> fresh;
    set<pair<int,int>>  rotten;
    set<pair<int,int>> infected;
    
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j]==1)
                    fresh.insert({i,j});
                else if(grid[i][j]==2)
                    rotten.insert({i,j});
            }
        }
        
        int ret = 0;
        int dir[4][2] = {{0,1}, {1,0}, {-1,0},{0,-1}};
        
        while(fresh.size()>0)
        {
            for(set<pair<int,int>>:: iterator itr = rotten.begin(); itr!=rotten.end(); itr++)
            {
                int i = itr->first;
                int j = itr->second;
                
                for(int k=0; k<4; k++)
                {
                    int ni = i+ dir[k][0];
                    int nj = j+ dir[k][1];
                    set<pair<int,int>>:: iterator c = fresh.find({ni,nj});
                    if(c!=fresh.end())
                    {
                        fresh.erase(c);
                        infected.insert({ni,nj});
                    }
                }  
            }
            
            if(infected.size()==0)
                    return -1;
                
            rotten=infected;
            infected.clear();
            ret++;
        }
        
        return ret;
    }
};
