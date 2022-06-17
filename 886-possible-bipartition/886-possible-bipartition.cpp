class Solution {
public:
   
    bool solve(vector<vector<int>>&graph, int i, int col, vector<int>&color){
        
        color[i] = col;
        
        for(auto x: graph[i]){
            if(color[x] == color[i])
                return false;
            
            if(color[x] == 0 && !solve(graph, x, -col, color))
                return false;
 
        }
        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        
        for(auto i: dislikes) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        vector<int> color(n+1, 0);
        
        for(int i=1;i<=n;i++){
            if(color[i] == 0 && !solve(graph, i, 1, color))
                return false;
        }
        
        return true;
    }
};