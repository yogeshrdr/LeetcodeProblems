class Solution {
public:
    string solve(string str1, string str2){
        
        int s1 = str1.size(); 
        int s2 = str2.size();
        
        int dp[s1+1][s2+1];
        
        string ans; 
        int max = 0;
        
        for(int i=0;i<s1+1;i++)
            dp[i][0] = 0;
        
        for(int i=0;i<s2+1;i++)
            dp[0][i] = 0;

        for(int i=1;i<s1+1;i++){
            for(int j=1;j<s2+1;j++){ 
                
               if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    if(dp[i][j]>max){
                        string temp = str1.substr(i-dp[i][j], dp[i][j]) ;
                        
                        string newtemp = string(temp.rbegin(),temp.rend());
                        
                        if(newtemp==temp){
                            max = dp[i][j];
                            ans = temp;
                        }
                    }
                }
                else
                dp[i][j] = 0; 
            }
        }

        return ans;
    }
    string longestPalindrome(string s) {
        string temp = string(s.rbegin(),s.rend());
        return solve(s, temp); 
    }
};