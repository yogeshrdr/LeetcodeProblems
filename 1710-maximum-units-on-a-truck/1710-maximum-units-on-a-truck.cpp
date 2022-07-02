class Solution {
public:  
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
         sort(boxTypes.begin(),boxTypes.end(), cmp);
		
        int ans=0;
        
        for(auto i: boxTypes){
            int x = min(i[0], truckSize);
            
            ans += x*i[1];
            
            truckSize = truckSize - x;
            
            if(!truckSize) 
                break;
        }
        
        return ans;
    }
};