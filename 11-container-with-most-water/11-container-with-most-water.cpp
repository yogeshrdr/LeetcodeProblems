class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxWater = INT_MIN;
        
        while(l<r){
            int minHeight = min(height[l], height[r]);
            
            maxWater = max(maxWater, minHeight * (r-l));
            
            if(height[l] > height[r])
                r--;
            else
                l++;
        }
        
        return maxWater;
    }
};