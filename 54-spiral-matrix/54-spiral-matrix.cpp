class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size()-1;
        int t = 0;
        int b = matrix.size()-1;
        
        vector<int> ans;

        
        while(l<=r && t<=b){
            for(int i=l;i<=r;i++)
                ans.push_back(matrix[t][i]);
            
            t++;
            
            for(int i=t;i<=b;i++)
                ans.push_back(matrix[i][r]);
            
            r--;
            
            if(l > r || t > b)
                break;
            
            for(int i=r;i>=l;i--)
                ans.push_back(matrix[b][i]);
            
            b--;
            
            for(int i=b;i>=t;i--)
                ans.push_back(matrix[i][l]);
            
            l++;
            
        }
        
        
        return ans;
    }
};