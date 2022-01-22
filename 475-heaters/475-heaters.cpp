class Solution {
public:

    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        vector<int> v(houses.size(), INT_MAX); 
        
        int i=0, j=0;
        
        while(i<houses.size() && j<heaters.size()) {
            if (houses[i] <= heaters[j]) { 
                v[i] = heaters[j] - houses[i]; 
                i++; 
            }
            else  
                j++; 
        }
        
        
        i = houses.size()-1, j = heaters.size()-1;
        
        
        while(i>=0 && j>=0) {
            if (houses[i] >= heaters[j]) { 
                v[i] = min(v[i], houses[i] - heaters[j]); 
                i--; 
            }
            else  
                j--;
        }
        
        
        return *max_element(v.begin(), v.end());
    }
};