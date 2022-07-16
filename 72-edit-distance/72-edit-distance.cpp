class Solution {
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>>&dp){
        
        if(j==0)
            return i;
        
        if(i==0)
            return j;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(word1[i-1] == word2[j-1])
            return dp[i][j] = solve(word1, word2, i-1, j-1, dp);
        
        else{
            int insert = solve(word1, word2, i, j-1, dp);
            int del = solve(word1, word2, i-1, j, dp);
            int rep = solve(word1, word2, i-1, j-1, dp);
            
            return dp[i][j] =  1 +  min({insert, del, rep});
            
        }
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        
        return solve(word1, word2, word1.size(), word2.size(), dp);
    }
};