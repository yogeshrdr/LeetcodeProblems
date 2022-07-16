class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(abs(n-m) > 1)
            return false;
        
        if(s == t)
            return false;
        
        int i=0,j=0;
        
        while(i<n && j<m && s[i] == t[j]){
            i++;
            j++;
        }
        
        if(i==n && j==m)
            return false;
        
        if(n>m){
            string s1 = s.substr(i+1);
            string s2 = t.substr(j);
            
            return s1 ==  s2;
        }
        
        if(n<m){
            string s1 = s.substr(i);
            string s2 = t.substr(j+1);
            
            return s1 ==  s2;
        }
        
        if(n==m){
            string s1 = s.substr(i+1);
            string s2 = t.substr(j+1);
            
            return s1==s2;
        }
        
        return false;
    }
}; 