// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, r=n, pos=1, mid;
        
        while(r>=l){
            mid = l + (r-l)/2;
            bool x = isBadVersion(mid);
            if(x==true){
                pos = mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        
        return pos;
    }
};