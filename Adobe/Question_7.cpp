// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:              //NOTE: 1.assume worst when things happen to u
                             //2.do ur best at ur turn
   int dp[1001][1001];
    int solve(vector<int> &A,int n,int i,int j)
    {
        //base case
       if(i>j)
       return 0;
       if(i==j)
       return A[i];
       if(dp[i][j]!=-1)
       return dp[i][j];
       //if X choses i th pot
          //Y can either chose i+1 or j
       int v1=A[i]+min(solve(A,n,i+2,j),solve(A,n,i+1,j-1));
       //if X choses j th pot
         //Y can either choose i or j-1
       int v2=A[j]+min(solve(A,n,i+1,j-1),solve(A,n,i,j-2));
      
       return dp[i][j]=max(v1,v2);
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    memset(dp,-1,sizeof(dp));
	    int i=0,j=n-1;
	    return solve(A,n,i,j);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
