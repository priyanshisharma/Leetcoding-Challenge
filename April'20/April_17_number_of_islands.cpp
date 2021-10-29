class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j] == '1'){
            grid[i][j] = '*';
            dfs(grid,i+1,j,n,m);
            dfs(grid,i-1,j,n,m);
            dfs(grid,i,j+1,n,m);
            dfs(grid,i,j-1,n,m);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(NULL);
        cin.tie(0);
        cout.tie(0);
        
        int c = 0;
        int rowc = grid.size();
        if(rowc == 0) return 0;
        int colc = grid[0].size();
        
        for(int i=0;i<rowc;i++)
            for(int j = 0;j<colc;j++)
                if(grid[i][j] == '1')
                {
                    c++;
                    dfs(grid,i,j, rowc,colc);
                }
        
        return c;
    }
};