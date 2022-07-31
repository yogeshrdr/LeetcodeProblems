class Solution {
public:
    int solve(int headID, vector<vector<int>>&adj, vector<int>& informTime) {
        int temp = 0;
        
        for (auto i : adj[headID])
            temp = max(temp, solve(i , adj, informTime));
        
        return informTime[headID] + temp;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        
        return solve(headID, adj, informTime);
    }
};