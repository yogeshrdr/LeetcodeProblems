class Solution {
public:
   void solve(int col, vector<int>&leftR,vector<int>&upperD,vector<int> lowerD ,int n, int&count){
      if(col == n) {
          count++;
            return; 
        }
    
       for(int row=0;row<n;row++){
           if(leftR[row] == 0 && upperD[row+col] == 0 && lowerD[n-1 + col - row] == 0){
               leftR[row] =1;
               upperD[row+col] = 1;
               lowerD[n-1 + col - row] = 1;
               
               solve(col+1, leftR, upperD, lowerD, n, count);
               
               leftR[row] =0;
               upperD[row+col] = 0;
               lowerD[n-1 + col - row] = 0;
               
           }
       }
    }
    
    
    
    int totalNQueens(int n) {        
        vector<int> leftR(n,0);
        vector<int> upperD(2*n-1, 0);
        vector<int> lowerD(2*n-1, 0);
        
        int count = 0;
        
        solve(0, leftR, upperD, lowerD, n, count);
        
        return count;
    }
};