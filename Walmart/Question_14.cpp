// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string str,int k,int idx,int n,string &ans)
    {
        //base case
        if(k==0)
        return;
        char ch1=str[idx];
        for(int j=n-1;j>idx;j--)
        {
            if(ch1<str[j])
            ch1=str[j];
        }
        if(ch1!=str[idx])       
        k--;
        for(int j=n-1;j>=idx;j--)
        {
            if(str[j]==ch1)
            {
                swap(str[j],str[idx]);
                if(ans<str)
                ans=str;
                solve(str,k,idx+1,n,ans);
                swap(str[j],str[idx]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        int n=str.size();
        string ans=str;
        solve(str,k,0,n,ans);
        //swap(str[0],str[1]);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends