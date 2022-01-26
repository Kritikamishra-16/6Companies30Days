// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int res=0,f=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='0' and str[i]<='9')
            {
            char ch=str[i];
            res=res*10+(ch-'0');
            }
            else if(str[i]=='-')
            {
                f=1;
                continue;
            }
            else 
            return -1;
        }
        if(f)
        res=res*-1;
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
