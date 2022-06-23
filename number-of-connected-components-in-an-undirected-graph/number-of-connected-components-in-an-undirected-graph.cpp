class Solution {
public:
    vector<int> parent;
    
    int find(int x){
        while(x != parent[x])
            x = parent[x];
        
        return x;
    }
    
    
    void Union(int x, int y){
        int rootA   = find(x);
        int rootB   = find(y);
        
        if(rootA!=rootB)
            parent[rootA] = rootB;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<n;i++)
            parent.push_back(i);
        
        for(auto i: edges){
            int x = i[0];
            int y = i[1];
            
            Union(x, y);
        }
        
        
        int count = 0;
        
        for(int i=0;i<parent.size();i++)
            if(i == parent[i])
                count++;
        
        return count;
    }
};