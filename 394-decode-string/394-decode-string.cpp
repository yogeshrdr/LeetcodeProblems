class Solution {
public:
    string decodeString(string s) {
        stack<int> s1;
        stack<string> s2;
        
        string temp;
        
        int x = 0;
        
        for(auto i:s){
            if(isdigit(i))
                x = x*10 + i - '0';
            
            
            else if(i == '['){
                s1.push(x);
                s2.push(temp);
                temp = "";
                x = 0;
            }
            
            else if(i == ']'){
                string temp1 = s2.top();
                s2.pop();
                
                int j = s1.top();
                
                while(j>0){
                    temp1 = temp1 + temp;
                    j--;
                }
                
                s1.pop();
                
                temp = temp1;
            }
            
            else
                temp = temp +i;
            
        }
        
        return temp;
    }
};