class Solution {
public:
    int integerBreak(int n) {
        int t[n+1][n];
        
        for(int i=0;i<n+1;i++)
            t[i][0] =1;
        
        for(int i=0;i<n;i++)
            t[0][i] = 1;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n;j++){
                if(i < j)
                    t[i][j] = t[i][j-1];
                else
                    t[i][j] = max(t[i][j-1], j * t[i-j][j]);
            }
        }
        
        return t[n][n-1];
    }
};