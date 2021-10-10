class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      if (right>left){
           return rangeBitwiseAnd(left>>1, right>>1)<<1;
       }else{
           return left;
       }
    }
};