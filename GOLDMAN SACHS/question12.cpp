// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
   long long dp[100005];
   void precompute(long long N)
   {
       dp[0]=0;
       dp[1]=1;
       for(long long i=2;i<=N;i++)
       {
           dp[i]=i*i+dp[i-1];
       }
   }
    long long squaresInChessBoard(long long N) {
        precompute(N);
        return dp[N];
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  // } Driver Code Ends