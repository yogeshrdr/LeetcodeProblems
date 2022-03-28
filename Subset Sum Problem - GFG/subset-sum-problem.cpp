// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int dp[sum + 1];
        
        for(int i=0;i<=sum+1;i++)
            dp[i] = 0;
        
        
        dp[0] = 1;
        
        for(int i=0;i<arr.size();i++){
            
            for(int j=sum;j>=arr[i];j--){
                if (dp[j - arr[i]] == 1)
                    dp[j] = 1;
            }
        }
        
        
        return dp[sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends