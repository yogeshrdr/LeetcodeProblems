class Solution {
public:
     
    int find(int i, vector<int>& parent){
        if(parent[i] == i) 
            return i;
        
        return parent[i] = find(parent[i], parent);
    }
    
    void Union(int city1, int city2, vector<int>& rank, vector<int>& parent){
        int x1 = find(city1, parent);
        int x2 = find(city2, parent);

        if(rank[x1] == rank[x2]){
            parent[x2] = x1;
            rank[x1]++;
        }
        
        else if(rank[x1] > rank[x2])
            parent[x2] = x1;
        
        else
            parent[x1] = x2;
    }
    
    void makeSet(int n, vector<int>& parent){
       
    }
       
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size();
        
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    Union(i, j, rank, parent);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i)
                ans++;
        }
        
        
        return ans;
       
    }
};