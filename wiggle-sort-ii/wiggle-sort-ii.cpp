class Solution {
public:
    void wiggleSort(vector<int>& nums) {
      sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp(n);
       
        int i=1, j=n-1;
        
        while(i<n){
            temp[i] = nums[j];
            i +=2;
            j--;
        }
        
        i=0;
        while(i<n){
            temp[i] = nums[j];
            i +=2;
            j--;
        }
        
        for(i=0;i<n;i++){
            nums[i] = temp[i];
        }
        
    }
};