class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i,int j, vector<vector<int>>&dp){
        if(i<0 || j<0 || i>= matrix.size()|| j>=matrix[0].size()|| matrix[i][j] == '0')
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        
        return dp[i][j] = 1+min( solve(matrix,i+1,j,dp), min( solve(matrix,i+1,j+1,dp), solve(matrix,i,j+1,dp) )) ;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = INT_MIN ;
        
       vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1)) ;
        
        for(int i=0;i<matrix.size() ;i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == '1')
                    ans = max(ans, solve(matrix, i, j, dp)) ;  
            }
        }
        
        return ans == INT_MIN? 0:ans*ans;
    }
};