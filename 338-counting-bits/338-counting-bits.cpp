class Solution {
public:
    
    int solve(int n){
        if(n==0)
            return 0;
        
        if(n==1)
            return 1;
        
        if(n%2 == 0)
            return solve(n/2);
        
        else
            return 1 + solve(n/2);
    }
    
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        
        for(int i=0;i<n+1;i++)
            v[i] = solve(i);
        
        return v;
    }
};