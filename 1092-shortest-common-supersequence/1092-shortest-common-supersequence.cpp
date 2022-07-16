class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++)
            dp[i][0] = i;
        
        for(int i=0;i<m+1;i++)
            dp[0][i] = i;
        
        
        for(int i=1;i<n+1;i++)
            for(int j=1;j<m+1;j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        
        
        string ans = "";
        
        int i=n, j=m;
        
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            
            
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans += str2[j-1];
                    j--;
                }
                else{
                    ans += str1[i-1];
                    i--;
                }
                    
            }
            
        }
        
        while(i>0){
            ans += str1[i-1];
            i--;
        }
        
        while(j>0){
            ans += str2[j-1];
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};