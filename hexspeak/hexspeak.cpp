class Solution {
public:
    string toHexspeak(string num) {
        long n = stol(num);
        string res;
        
        while(n){
            char c;
            long r = n%16;
            if(r<10 && r>1) 
                 return string("ERROR");
            else if (r==0) 
                c = 'O';
            else if (r==1) 
                c = 'I';
             else 
                 c = 'A'+r-10;
            res.insert(res.begin(), c);
             n = n / 16;
        }
         return res;
    }
};