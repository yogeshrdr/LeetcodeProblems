class Solution {
public:
    int calculate(string s){
        
        stack<int> stk;
        char sign = '+';
        long int temp = 0;
    
        for (long int i=0;i<s.length();i++){
            
            if(isdigit(s[i]))
                temp = 10 * temp + s[i]-'0';
            
            if(!isdigit(s[i]) && !isspace(s[i]) || i==s.size()-1){
                if (sign == '-')
                    stk.push(-temp);
                
                else if(sign == '+')
                    stk.push(temp);
                
                else{
                    int num;
                    
                    if(sign == '*' )
                        num = stk.top()*temp;
                    else
                        num = stk.top()/temp;
                    stk.pop();
                    stk.push(num);
                } 
                
                sign = s[i];
                temp = 0;
            }
            
        }
        
        int ans = 0;
        
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
};