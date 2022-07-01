class Solution {
public:
    
    void dfs(vector<vector<int>>&adj, int src, vector<bool>&visited) {
        visited[src] = true;
        
        for (auto i : adj[src]) {
            if(!visited[i])
                dfs(adj, i, visited);
        }
    }

    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        
        vector<vector<int>> adj(n);
        
        for (auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        dfs(adj, source, visited);
        
        return visited[destination];
    }
};