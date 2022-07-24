class Solution {
public:
    
    bool solve(vector<vector<int>>&grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return false;
        
        if(grid[i][j] == 1)
            return true;
        
        grid[i][j] = 1;
        
        bool x1 = solve(grid, i+1, j);
        bool x2 = solve(grid, i-1, j);
        bool x3 = solve(grid, i, j-1);
        bool x4 = solve(grid, i, j+1);
        
        return  x1 &&  x2 && x3 && x4;
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    if(solve(grid, i, j))
                        ans +=1;
                }
            }
        }
        
        return ans;
    }
};