// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSackRec(int W, int wt[],int val[], int n,int** t){
        if (n < 0 || W <=0)
            return 0;

        if (t[n][W] != -1)
            return t[n][W];
 
        if (wt[n] > W) {
            t[n][W] = knapSackRec(W, wt,val,n- 1,t);
            return t[n][W];
        }
        else {
            t[n][W] = max(val[n]+ knapSackRec(W-wt[n],wt,val,n-1,t),knapSackRec(W,wt,val,n-1,t));
            return t[n][W];
        }
}

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
     
        int** t;
        t = new int*[n];
 
        for (int i = 0; i < n; i++)
            t[i] = new int[W + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < W + 1; j++)
                t[i][j] = -1;
        return knapSackRec(W, wt, val, n - 1, t);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends