class Solution {
public:
    int solve(string text1, string text2, int i, int j){
        if(i==0 || j==0)
            return 0;
        
        if(text1[i-1] == text2[j-1])
            return 1 + solve(text1, text2, i-1, j-1);
        else
            return max(solve(text1, text2, i-1, j), solve(text1, text2, i, j-1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
            
        if(n==0 || m==0)
            return 0;
        
        int dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
            for(int j=0;j<m+1;j++)
                dp[i][j] = 0;
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        
        
        int i=n, j=m;
        string lcs = "";
        
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                lcs += text1[i-1];
                i--;
                j--;
            }
            
            else if(dp[i-1][j] > dp[i][j-1])
                j--;
            
            else
                i--;
            
                
        }
        
        reverse(lcs.begin(), lcs.end());
        
        cout<<lcs<<endl;
        
        
        return dp[n][m];
    }
};