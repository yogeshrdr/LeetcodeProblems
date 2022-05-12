class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int i=0;
        
        int maxP = INT_MIN;
        
        for(int j=0;j<prices.size();j++){
            if(prices[i]<=prices[j])
                maxP = max(maxP, prices[j]-prices[i]);
            else
                i =j;
        }
        
        return maxP;
    }
};