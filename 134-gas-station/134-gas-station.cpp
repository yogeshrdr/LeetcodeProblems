class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         
        int total_cost=0;
        int total_fuel=0;
        int n=cost.size();
        
        for(int i=0;i<n;i++){
            total_cost+=cost[i];
            total_fuel+=gas[i];
        }
       
        if(total_fuel<total_cost)
            return -1;
        
        int curr_fuel=0;
        int index=0;  
        
        for(int i=0;i<n;i++){
            if(curr_fuel<0){
                index=i;
                curr_fuel=0;
            }
            curr_fuel+=(gas[i]-cost[i]);
        }
        
        return index;
    }
};