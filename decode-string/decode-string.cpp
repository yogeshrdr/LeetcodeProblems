class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else{
                
               string temp = "";
               while(st.top() != '['){
                    temp = st.top() + temp ;
                    st.pop();
                }
                
               st.pop();
               
               string num = "";
               
               while(!st.empty() && isdigit(st.top())){
                   num = st.top() + num;
                   st.pop();
               }
               
               int k = stoi(num);   
               
               while(k--){
                   for(int l=0;l<temp.size();l++){
                       st.push(temp[l]);
                   }
               }
           }
        }
        
        string str = "";
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }
        return str;

    }
};