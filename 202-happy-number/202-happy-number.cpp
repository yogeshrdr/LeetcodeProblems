class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> s;
        
        while(n!=1 && s.find(n)==s.end()){
            int sum = 0;
            int x = n;
            
            while(x>0){
                int i = x%10;
                x = x /10;
                sum += i *i;
            }
            
            s.insert(n);
            n = sum;
        }
        
        if(n==1)
            return true;
        else
            return false;
    }
};