// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int dp[10004];
    int solve(int arr[],int n)
    {
        if(n<0)
        return dp[n]=0;
        
        if(dp[n]!=-1)
        return dp[n];
        
        return dp[n]=max(arr[n]+solve(arr,n-2),solve(arr,n-1));
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        memset(dp,-1,sizeof(dp));
        return solve(arr,n-1);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends