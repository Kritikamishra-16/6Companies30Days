// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
    string res="";
    int l=0,u=0,count=0;
    while(u<src.length())
    {
        if(src[l]==src[u])
        {
            u++;
        }
        else if(src[l]!=src[u])
        {
            res+=src[l];
            count=(u-l-1)+1;
            res+=to_string(count);
            l=u;
        }
    }
    res+=src[l];
    res+=to_string(u-l);
    return res;
}     
 
