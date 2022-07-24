class Solution {
public:
    bool solve(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i<0 || j<0 || i>=grid2.size() ||  j>=grid2[0].size() || grid2[i][j]!=1)
            return true;
        
        if(grid1[i][j] == 0)
            return false;
        
        grid2[i][j] = 2;
        
        int x1 = solve(grid1, grid2, i+1, j);
        int x2  = solve(grid1, grid2, i-1, j);
        int x3 = solve(grid1, grid2, i, j+1);
        int x4 = solve(grid1, grid2, i, j-1);
        
        return x1 && x2 && x3 && x4;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        
        for(int i=0;i<grid2.size();i++)
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j] == 1){
                    if(solve(grid1, grid2, i, j))
                        ans++;
                }
            }
        
        return ans;
    }
};