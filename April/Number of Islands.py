class Solution(object):
    def numIslands(self, grid):
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.search(grid, i, j)
                    count += 1
        return count

    def search(self, grid, i, j):
        if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j] != '1':
            return
        grid[i][j] = '-'
        self.search(grid, i+1, j)
        self.search(grid, i-1, j)
        self.search(grid, i, j+1)
        self.search(grid, i, j-1)