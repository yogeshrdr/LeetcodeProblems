class Solution {
public:
    string solve(string&s, int&i){
        string temp;
        
        while(i<s.length() && s[i]!=']'){
            
            if(isdigit(s[i])){
                int k = 0;
                
                while(i<s.length() && isdigit(s[i])){
                    k = k*10 + s[i] - '0';
                    i++;
                }
                
                i++;
                
                string x = solve(s, i);
                
                while(k>0){
                    temp += x;
                    k--;
                }
                
            }
            
            else
                temp+=s[i];
            
            i++;
        }
        
        return temp;
    }
    
    
    string decodeString(string s) {
        int i=0;
        return solve(s,i);
    }
};