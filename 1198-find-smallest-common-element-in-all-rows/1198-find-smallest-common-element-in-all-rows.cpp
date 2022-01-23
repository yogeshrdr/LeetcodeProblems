class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
       int n = mat.size(), m = mat[0].size();
        
        for(int j = 0; j < m; j++){
            
            int num = mat[0][j], flag = 1;
            
            for(int i = 1; i < n; i++){
                
                auto it = lower_bound(mat[i].begin(), mat[i].end(), num);
                
                if(it == mat[i].end() || *it != num){
                    flag = 0;
                    break;
                }
            }
            
            if(flag)
                return num;
        }
        return -1;
        
        
    }
};