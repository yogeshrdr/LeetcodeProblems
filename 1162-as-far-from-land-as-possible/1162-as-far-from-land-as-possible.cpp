class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int ans = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j] == 1)
                    q.push({i,j});
        
        vector<pair<int, int>> dir {{0,1}, {1,0}, {-1,0}, {0,-1}};
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(auto x: dir){
                int i = curr.first + x.first;
                int j = curr.second + x.second;
                
                if(i>=0 && i<grid.size() && j>=0 && j<grid.size() && grid[i][j] == 0){
                    grid[i][j] = grid[curr.first][curr.second] + 1;
                    q.push({i,j});
                    ans = max(grid[i][j], ans);
                }
            }
            
            
        }
        
        
        return ans-1;
        
    }
};