class Solution {
public:
    void solve(vector<vector<int>>&grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
            return;
        
        
        grid[i][j] = 2;
        
        solve(grid, i-1, j);
        solve(grid, i, j-1);
        solve(grid, i+1, j);
        solve(grid, i, j+1);

    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        
        int flag = false;
        
        for(int i=0;i<grid.size();i++){
            if(flag == true)
                break;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    solve(grid, i, j);
                    
                    flag = true;
                    break;
                }
                
            }
            
            
        }

        
        
        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
                    v1.push_back({i,j});
                
                if(grid[i][j] == 1)
                    v2.push_back({i,j});
            }
        }
        
        
        for(auto i: v1){
            for(auto j:v2){
                int x = abs(i.first - j.first) + abs(i.second - j.second);
                ans = min(ans, x);
            }
        }
        
        
        return ans-1;
    }
};