class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        vector<pair<int,int>> dir = {{1,0},{0,1}, {-1,0}, {0,-1}};
        
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j] == 1){
                    ans +=4;
                    
                    for(auto k: dir) {
                        int x = i+k.first;
                        int y = j+k.second; 
                        
                        if (x<0 ||x==grid.size() ||y<0 || y==grid[0].size() || grid[x][y] == 0) 
                            continue;
                        
                        ans--;
                    }
                }
                
            }
        }
        
        
        return ans;
        
    }
};