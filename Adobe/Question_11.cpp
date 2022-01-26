// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string res="";
    string amendSentence (string s)
    {
        int j=0,n=s.length();
        while(j<n)
        {
            if(s[j]>='A' and s[j]<='Z')
            {
                if(res.length()!=0)
                res+=" ";
                res+=(s[j]+32);
            }
            else{
                res+=s[j];
            }
            j++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
