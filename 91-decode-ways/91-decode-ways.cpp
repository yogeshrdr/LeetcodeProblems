class Solution {
public:
    int solve(string s, int i){
        if(s[i] == '0')
            return 0;
        
        if(i >= s.size()-1)
            return 1;
        
        string temp = s.substr(i, 2);
        
        int op1 = solve(s, i+1);
        int op2 = (stoi(temp)>=10 && stoi(temp)<=26) ? solve(s, i+2) : 0;
        
        return op1+op2;
    }
    
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        if(s[0]=='0')
            return 0;
        
        if(n==1)
            return 1;
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<n+1;i++){
            string temp = s.substr(i-2,2);
            
            if(s[i-1]!='0')
                dp[i] += dp[i-1];
            
            if(stoi(temp) >= 10 && stoi(temp) <= 26)
                dp[i] += dp[i-2];
            
        }
        
        return dp[n];
    }
};