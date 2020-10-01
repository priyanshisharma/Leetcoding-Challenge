class Solution {
public:
  int uniquePathsIII(vector<vector<int>>& grid) {        
    int start_i = -1, start_j = -1; // Location of starting point in grid
    int n = 1; // Tracks the total count of Zeros in the grid
      
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j){
        if (grid[i][j] == 0) 
            ++n;
        else if (grid[i][j] == 1) { 
            start_j = j; start_i = i; }   
      }
    return dfs(grid, start_i, start_j, n);
  }
    

  int dfs(vector<vector<int>>& grid, int i, int j, int n) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == -1) return 0;
      
    if (grid[i][j] == 2) 
        return n == 0;
        //Returns 1 when n is equal to 0 ( means all empty squares are visited i.e. one path found)
        //Returns 0 when n!=0
      
    grid[i][j] = -1; // Changing to -1 so that its not visited again.
    int paths = dfs(grid, i, j+1, n - 1) + dfs(grid, i, j-1,  n - 1) + dfs(grid, i+1, j, n - 1) + dfs(grid, i-1, j, n - 1);
    grid[i][j] = 0; // Reverting back to 0 after processing.
    return paths;        
  }
};