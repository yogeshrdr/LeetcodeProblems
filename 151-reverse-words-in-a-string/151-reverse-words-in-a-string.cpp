class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        for (int i=0;i<s.length();i++) {
            
            if (s[i] == ' ') 
                continue;
            
            int pos = i;
            
            while (i<s.length() && s[i] !=' ') 
                i++;
            
            if (ans.length() > 0) 
                ans = ' ' + ans;
            
            ans = s.substr(pos, i - pos) + ans;
        }
        
        return ans;
    }
};