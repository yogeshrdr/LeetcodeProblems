class Solution {
public:
    vector<string> alp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void solve(string digits, vector<string>&ans, string&temp, int idx){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        int x = digits[idx] - '0';
        string str = alp[x];
        
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            solve(digits, ans, temp, idx+1);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.size() <=0)
            return ans;
        
        string temp;
        
        solve(digits, ans, temp, 0);
        
        return ans;
    }
};