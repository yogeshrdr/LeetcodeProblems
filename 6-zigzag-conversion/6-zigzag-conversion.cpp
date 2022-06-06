class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;
        
        vector<string> v(numRows, "");
        
        int i=0, j=0;
        
        while(i<s.length()){
            while(i<s.length() && j<numRows-1)
                v[j++] += s[i++];
            
            while(i<s.length() && j > 0)
                v[j--] += s[i++];
            
        }
        
        string ans = "";
        
        for(auto i:v){
            ans += i;
        }
        
        return ans;
    }
};