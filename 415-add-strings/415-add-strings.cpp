class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i=num1.size()-1;
        int j=num2.size()-1;
        string ans = "";
        
        while(i>=0 || j>=0){
            int x = i>=0 ? num1[i] - '0' : 0;
            int y = j>=0 ? num2[j] - '0' : 0;
            
            int z = x+y+carry;
            carry = z/10;
            z = z%10;
            
            ans += to_string(z);
            
            i--;
            j--;
        }
        
        if(carry != 0)
            ans += to_string(carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};