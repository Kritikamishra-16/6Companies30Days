// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
//BEST TIME TO BUY AND SELL STOCK WITH AT MOST K TRANSACTIONS

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        int dp[K+1][N];
        for(int t=0;t<K+1;t++)
        {
            for(int d=0;d<N;d++)
            {
                if(t==0 || d==0)
                dp[t][d]=0;
            }
        }
        for(int t=1;t<K+1;t++)
        {
            for(int d=1;d<N;d++)
            {
                int p=INT_MIN;
                for(int prev_d=0;prev_d<d;prev_d++)
                {
                    p=max(p,dp[t-1][prev_d]+(A[d]-A[prev_d]));
                }
                dp[t][d]=max(dp[t][d-1],p);
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
