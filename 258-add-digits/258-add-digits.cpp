class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        
        int ans = num;
       
        while(ans > 9){
            int sum = 0;
            while(num>0){
                int i = num%10;
                sum = sum +i;
                num = num/10;
            }
            ans = sum;
            num = sum;
        }
        
        return ans;     
        
    }
};