class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int ans = 0;
        int count = 0;
        
        
        int i=1;
        
        while(i<arr.size()){
            
            if(arr[i]==arr[i-1])
                count = 0;
            
            else if(arr[i]>arr[i-1])
                count++;
            
            else if(count>0){
                
                    while(i<arr.size() and arr[i]<arr[i-1]){
                        count++; 
                        i++;
                    }
                
                    ans = max(ans, count+1);
                    count=0;
                i--;
            }
            
            i++;
        }
        
        return ans;
    }
};