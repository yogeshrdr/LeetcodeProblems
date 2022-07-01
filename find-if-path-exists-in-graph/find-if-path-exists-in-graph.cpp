class Solution {
public:
    int find(vector<int>&parent, int x){
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent, parent[x]);
    }
    
    void Union(vector<int>&parent, int x, int y){
        int i = find(parent, x);
        int j = find(parent, y);
        
        parent[i] = j;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        for(auto i: edges)
            Union(parent,i[0], i[1]);
        
        return find(parent, source) == find(parent, destination);
    }
};