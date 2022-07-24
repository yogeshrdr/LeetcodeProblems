class Solution {
public:
    void solve(vector<vector<int>>&grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1)
            return;
        
        grid[i][j] = 0;
        
        solve(grid, i-1, j);
        solve(grid, i+1, j);
        solve(grid, i, j-1);
        solve(grid, i, j+1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1) && grid[i][j] == 1)
                    solve(grid, i, j);
            }
        }
        
        
        int ans = 0;
        
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1)
                    ans ++;
            }
        
        return ans;
    }
};