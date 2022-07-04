// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvis){
        visited[node]=true;
        dfsvis[node]=true;
        
        for(auto i : adj[node]){
            if(!visited[i]){
                if(solve(i, adj, visited, dfsvis)) 
                    return true;
            }
            
            else if(dfsvis[i]) 
                return true;
        }
        
        dfsvis[node]=false;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> dfsvis(V, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]){
                if(solve(i, adj, visited, dfsvis)) 
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends