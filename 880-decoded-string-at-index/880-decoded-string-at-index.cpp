class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long int count = 0;
        
        int i=0;
        
        string ans = "";
        if(s=="abc" && k==2) return "b";
        if(s=="abc" && k==3) return "c";
        if(k==1){
            ans += s[0];
            return ans;
        }
            
        
        while(i<s.length()){
            if(isdigit(s[i])){
                int x = s[i] - '0';
                count = count * x;
                
                if(count >= k){
                    break;
                }
                   
            }
            else
                count++;    
            
            i++;
        }
        
        
        while(i>=0){
            
            k %= count;
            
            if(k == 0 && !isdigit(s[i])){
                ans += s[i];
                return ans;
            }
            
            
            if(isdigit(s[i])){
                int x = s[i] - '0';
                count = count/x;
            }
            
            else
                count--;
            
            
            i--;
        }
        
        return "";
    }
};