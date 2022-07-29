class Solution {
public:
    bool isPlaindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    void solve(string&s, vector<vector<string>>&ans, vector<string>&temp, int idx){
        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<s.length();i++){
            
            if(isPlaindrome(s, idx, i)){
                string x = s.substr(idx, i-idx+1);
                temp.push_back(x);
                solve(s, ans, temp, i+1);
                temp.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(s, ans, temp, 0);
        
        return ans;
    }
};