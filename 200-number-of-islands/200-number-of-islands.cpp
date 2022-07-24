class Solution {
public:
    
    void solve(vector<vector<char>>&grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] != '1')
            return;
        
        grid[i][j] = '2';
        
        solve(grid, i-1, j);
        solve(grid, i+1, j);
        solve(grid, i, j-1);
        solve(grid, i, j+1);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    solve(grid, i, j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};