class Solution {
public:
    void markIslands(vector<vector<char>> &grid, int x, int y){
       if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!='1')
        return;

       grid[x][y] = 2;

       markIslands(grid,x+1,y);
       markIslands(grid,x,y+1);
       markIslands(grid,x-1,y);
       markIslands(grid,x,y-1);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {

        int no_of_islands = 0;

        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]=='1'){
                    markIslands(grid,i,j);
                    no_of_islands +=1;
                }

        return no_of_islands;
    }
};