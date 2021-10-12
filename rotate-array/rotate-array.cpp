class Solution {
public:
   void reverseArray(vector<int>& nums, int i,int j){  
       int temp;
       while (i < j)
       {   
          temp = nums[i];
          nums[i] = nums[j];
          nums[j] = temp;
          i++;
          j--;
       }
    }
    
    void rotate(vector<int>& nums, int k) {
       
       
       int n = nums.size();
       k %=n;
       reverseArray(nums, 0, n-1);
       reverseArray(nums, 0, k-1);
       reverseArray(nums, k, n-1); 
    }
};