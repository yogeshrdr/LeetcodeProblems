class Solution {
public:
    
    void bfs(vector<vector<int>>&adj, int src, vector<bool>&visited) {
        queue<int> q;
        visited[src] = true;
        
        q.push(src);
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            for(int i: adj[temp]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        
        vector<vector<int>> adj(n);
        
        for (auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        bfs(adj, source, visited);
        
        return visited[destination];
    }
};