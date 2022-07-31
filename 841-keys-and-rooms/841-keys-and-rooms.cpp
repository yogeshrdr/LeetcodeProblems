class Solution {
public:
    void solve(vector<vector<int>>&rooms, int i, vector<bool>&visited){
        visited[i] = true;
        
        for(int j=0;j<rooms[i].size();j++){
            if(!visited[rooms[i][j]])
                solve(rooms, rooms[i][j], visited);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        solve(rooms, 0, visited);
        
        for(auto i: visited)
            if(i ==  false)
                return false;
        
        return true;
    }
};