class Solution {
public:
    
    int find(vector<int>&parent, int x){
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent, parent[x]);
    }
    
    
    void Union(vector<int>&parent, vector<int>&rank, int x, int y){
        int i = find(parent, x);
        int j = find(parent, y);
        
        if(rank[i] == rank[j]){
            parent[j] = i;
            rank[i]++;
        }
        
        else if(rank[i] > rank[j])
            parent[i] = j;
        else
            parent[j] = i;
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<int> parent(n);
        vector<int> rank(n,0);
        
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(isConnected[i][j])
                    Union(parent,rank,i,j);
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                ans++;
        }
        
        return ans;
    }
};