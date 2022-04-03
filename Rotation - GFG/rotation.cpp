// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int l=0, r=n-1;
	    
        while (l <= r) {
            int m = l+(r-l)/2;
            int prev = (m-1+n)%n;
            int next = (m+1)%n;
 
            if (arr[m] <= arr[prev] && arr[m] <= arr[next])
                return m;
            else if (arr[m] <= arr[r])
                r = m-1;
            else if (arr[m] >= arr[l])
                l = m+1;
        }
        return 0;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends