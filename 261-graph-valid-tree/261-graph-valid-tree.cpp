class Solution {
public:
    vector<int> parent;
     
    int find(int x){
        while(parent[x]!=x)
            x = parent[x];
        
        return x;
    }
    
    bool Union(int x, int y){
        int rootA = find(x);
        int rootB = find(y);
        
        if(rootA == rootB)
            return false;
        
        parent[rootA] = rootB;
        return true;
    }
   
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
           return false;
        
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        
        for(auto i: edges){
            int x = i[0];
            int y = i[1];
            
            if(!Union(x,y))
                return false;
        }
        
        return true;
        
    }
};