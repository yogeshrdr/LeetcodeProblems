class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1);
        dp[0]=false;
        dp[1]=false;
        dp[2]=true;
        
        for(int i=3;i<=n;i++){
            if(dp[i-1]==false)
                dp[i]=true;
            else
                dp[i]=false;
            
        }
        
        return dp[n];
    }
};