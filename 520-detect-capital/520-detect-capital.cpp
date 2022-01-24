class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 0)
            return false;

        
        
        int count = 0;
        for(int i=0;i<word.size();i++)
            if(isupper(word[i]))
                count++;
        
        if(count == word.size() || count==0)
            return true;
        
        if(count == 1)
            if(isupper(word[0]))
                return true;
        
        return false;
    }
};