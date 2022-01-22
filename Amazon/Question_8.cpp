// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    int dp[1000006];
    long long solve(int m)
    {
        if(m==0 || m==1)
        {
            dp[m]=1;
            return dp[m];
        }
        if(dp[m]!=-1)
        {
            return dp[m];
        }
        dp[m]=solve(m-2)+1;
        return dp[m];
    }
    long long countWays(int m)
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        dp[m]=solve(m);
        
        return dp[m];
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends