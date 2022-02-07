class Solution {
public:
    void solve(vector<string>&ans, int open, int close , string temp){
        if(open==0 && close ==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(open!=0)
            solve(ans, open-1, close, temp+'(');
        if(close > open)
            solve(ans, open, close-1, temp+')');
            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        solve(ans, n, n, "");
        
        return ans;
    }
};