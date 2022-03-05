class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> minCost(n+1);
        
        for(int i=2;i<n+1;i++){
            int stepOne = cost[i-1] + minCost[i-1];
            int stepTwo = cost[i-2] + minCost[i-2];
            
            minCost[i] = min(stepOne, stepTwo);
        }
        
        return minCost[n];
    }
};