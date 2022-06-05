class Solution {
public:
    
    int solve(vector<int>& coins, int amount, int i){
       if(amount <= 0)
           return 0;
        
        if(i>=coins.size())
            return INT_MAX-1;
        
        if(amount < coins[i])
            return solve(coins, amount, i-1);
        else
            return min( solve(coins, amount, i-1), 1+solve(coins, amount - coins[i], i));
       
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1 , INT_MAX-1);
        
        dp[0] = 0;
        
        for(int i=1;i<amount+1;i++){
            for(int j=0;j<coins.size();j++){
               if(coins[j]<=i)
                   dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            } 
        }

        return dp[amount]  == INT_MAX -1 ?  -1 : dp[amount];
       
    }
};