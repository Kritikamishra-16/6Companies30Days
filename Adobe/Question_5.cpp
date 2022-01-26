// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int dp[1001][1001];
    long long int mod=1e9+7;
    int solve(int sum,int num,int x,int n)
    {
        if(sum==0)
        return 1;
        if(sum<0)
        return 0;
        if(dp[num][sum]!=-1)
        return dp[num][sum];
        int t=pow(num,x);
        if(t<=n)
        {
            int included=solve(sum-t,num+1,x,n)%mod;
            int not_included=solve(sum,num+1,x,n);
            return dp[num][sum]=(included+not_included)%mod;
        }
        else{
            return dp[num][sum]=0;
        }
    }
    int numOfWays(int n, int x)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(n,1,x,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
