class Solution {
public:
    int mySqrt(int x) {
        
        long long l=0, r=x;
        
        while(l<=r){
            long long m = l+(r-l)/2;
            
            if(m*m == x)
                return m;
            
            if(m*m < x && (m+1)*(m+1) > x)
                return m;
            
            else if(m*m < x)
                l = m+1;
            else if(m*m > x)
                r = m-1;
                
            
        }
        
        return -1;
    }
};