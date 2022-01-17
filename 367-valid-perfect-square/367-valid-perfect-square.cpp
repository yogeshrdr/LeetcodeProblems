class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0)
            return false;
        if(num == 0 || num  ==1)
            return true;
        
        long long l=0, r=num/2;
        
        while(l<=r){
            long long m = l+(r-l)/2;
            
            if(m*m == num)
                return true;
            else if(num<m*m)
                r = m-1;
            else
                l = m+1;
        }
        return false;
        
    }
};