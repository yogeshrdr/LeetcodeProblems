class Solution {
public:
    
    int find(int x, vector<int>&parent){
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x], parent);
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        
        vector<int> parent(n);
        
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        vector<int> rank(n, 0);
        
        for(auto i: logs){
            int x = find(i[1], parent);
            int y = find(i[2], parent);
            
            if(x!=y){
                n--;
                if(n==1)
                    return i[0];
                
                parent[x] = y;
            }
        }
        
        return -1;
    }
};