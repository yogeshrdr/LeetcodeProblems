class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0, r=letters.size()-1;
        
        char res = target;
        
        while(l<=r){
            int m = l+(r-l)/2;
            
            if(letters[m]<=target)
                l = m+1;
            else{
                res = letters[m];
                r =m-1; 
            }
               
        }
        
        if(l == letters.size())
            res = letters[0];
        
        return res;
    }
};