class Solution {
public:
    
    int solve(string s1, string s2, int i, int j){
        if(i==0 || j==0)
            return 0;
        
        if(s1[i-1] == s2[j-1])
            return 1 + solve(s1, s2, i-1, j-1);
        else
            return max(solve(s1, s2, i, j-1), solve(s1, s2, i-1, j));
    }
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        
        string s2 = s;
        
        int n = s.length();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        
        return dp[n][n];
    }
};