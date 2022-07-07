class Solution {
public:
    
    void solve(vector<int>&ans, int n, int i){
        if(i > n)
            return;
        
        if(i!=0)
            ans.push_back(i);
        
        for(int j=0;j<10;j++){
            
            if(i==0 && j==0)
                continue;
            
            solve(ans, n, i*10+j);
        }   
        
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        solve(ans, n, 0);
        
        return ans;
    }
};