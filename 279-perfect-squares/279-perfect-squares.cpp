class Solution {
public:
    
    int solve(int W, int n){
        if(W==0 || n==0)
            return INT_MAX;
        
        int i=n*n;
        
        if(i<=W){
            int temp=solve(W-i, n);
            return min(1+(temp==INT_MAX?0:temp),solve(W,n-1));
        }
        else
            return solve(W,n-1);
    }
        
    int numSquares(int n) {
        int x = sqrt(n);
        int dp[n+1][x+1];
        
        for(int i=0;i<n+1;i++)
            dp[i][0] = INT_MAX;
        
        for(int i=0;i<x+1;i++)
            dp[0][i] = INT_MAX;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<x+1;j++){
                int y = j*j;
                if(y<=i){
                    int temp = dp[i-y][j];
                    dp[i][j] = min(1 + (temp == INT_MAX?0:temp), dp[i][j-1]);
                }
                else
                    dp[i][j] = dp[i][j-1];
                
            }
        }
        
        return dp[n][x];
        
    }
};