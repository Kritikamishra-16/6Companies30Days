// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool subset_sum(int arr[],int n,int s)
    {
        if(s==0)    //if sum=0 then there is always an empty subset possible 
        return true;
        if(n==0)    //if we have not any elements then no subset possible 
        return false;
        if(arr[n-1]<=s)
        {
            return subset_sum(arr,n-1,s-arr[n-1])||subset_sum(arr,n-1,s);
        }
        else if(arr[n-1]>s)
        {
            return subset_sum(arr,n-1,s);
        }
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        return 0;
        return subset_sum(arr,N,sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
