// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    vector<int> v;//stores possible candidates for s1
    bool subset_sum(int arr[],int sum,int n)
    {
        bool t[n+1][sum+1];
        //initialization
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                t[i][j]=false;
                if(j==0)
                t[i][j]=true;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        for(int j=0;j<=sum/2;j++)
        {
            if(t[n][j]==true)
            v.push_back(j);
        }
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range=0;
	    for(int i=0;i<n;i++)
	    {
	        range+=arr[i];
	    }
	    subset_sum(arr,range,n);
	    int x=v[v.size()-1];
	    return (range-2*x);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
