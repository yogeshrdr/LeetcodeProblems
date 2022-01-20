class Solution {
public:
    bool isValid(vector<int>& piles, int h, int k){
        int count=0;
        
        for(int i=0;i<piles.size();i++){
            count+=piles[i]/k;
            
            if(piles[i]%k!=0)
                count+=1;
        }
        
        if(count > h)
            return false;
        
        return true;
    }
    
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(), piles.end());
        
        int ans=0;
        
        while(l<=r){
           int m=l+(r-l)/2;    
            
            if(isValid(piles,h,m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
        
    }
    
   
};