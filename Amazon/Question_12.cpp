// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        unordered_map<int,char> mp;
        char ch='A';
        for(int i=0;i<26;i++)
        {
            mp[i]=ch;
            ch++;
        }
        string str="";
        while(n!=0)
        {
            //makeing number 0 indexed
            n=n-1;
            int r=n%26;
            str=mp[r]+str;
            n=n/26;
        }
        return str;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends