class Solution {
public:
    bool divisorGame(int n) {
        if(n==1)
            return false;
        
        if(divisorGame(n-1) == false)
            return true;
        
        return false;
    }
};