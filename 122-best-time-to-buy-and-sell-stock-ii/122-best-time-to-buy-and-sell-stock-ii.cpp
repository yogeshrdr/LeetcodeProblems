class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i=0 , j=0;
        
        while(i<prices.size() && j<prices.size()){
            while(i<prices.size()-1 && prices[i]>prices[i+1]) 
                i++;
            
            j = i;
            
            while(j<prices.size()-1 && prices[j]<prices[j+1])
                j++;
            
            profit += prices[j] - prices[i];
            i = j+1;
        }
        
        return profit;
    }   
};