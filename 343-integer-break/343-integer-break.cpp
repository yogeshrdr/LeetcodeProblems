class Solution {
public:
    int solve(int n, int curr){
        
        if(n==0 || curr==0)
            return 1;
        
        if(curr > n)
            return solve(n, curr-1);
        else
            return max(solve(n, curr-1),  curr * solve(n-curr, curr));
    }
    
    int integerBreak(int n) {
        return solve(n, n-1);
    }
};