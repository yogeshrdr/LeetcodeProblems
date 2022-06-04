class Solution {
public:
    bool solve(string&s, set<string>&temp, int i){
        if(i == s.length())
            return true;
        
        for(int j=i+1;j<=s.length();j++){
            if(temp.find(s.substr(i, j-i)) != temp.end() && solve(s, temp, j))
                return true;
        }
        
        
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> temp;
        
        for(auto i: wordDict)
            temp.insert(i);
        
        vector<bool> dp(s.length() + 1);
        dp[0] = true;

        for (int i=1;i<=s.length();i++) {
            for (int j=0;j<i;j++) {
                
                if (temp.find(s.substr(j, i-j)) != temp.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
                
            }
        }
        
        
        return dp[s.length()];
    }
};