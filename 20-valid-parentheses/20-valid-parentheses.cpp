class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        unordered_map<char, char>mp;
        
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] =  '[';
        
        for(auto i:s){
            if(i == '(' || i == '{' || i == '[')
                st.push(i);
            else{
                if(st.empty())
                    return false;
                else if(st.top() == mp[i])
                    st.pop();
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};