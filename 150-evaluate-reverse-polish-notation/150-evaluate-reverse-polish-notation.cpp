class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        
        for(auto i: tokens){
            
            if(i=="+" || i=="-" || i=="*" || i=="/"){
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                
                    
                switch(i[0]){
                    case '+':
                        s.push(op1+op2);
                        break;
                    case '-':
                        s.push(op1-op2);
                        break;
                    case '*':
                        s.push(op1*op2);
                        break;
                    case '/':
                        s.push(op1/op2);
                        break;
                }
            }
            
            else
                s.push(stoi(i));
            
        }
        return s.top();
    }
};