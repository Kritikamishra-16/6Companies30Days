// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string> res;
	for(int i=1;i<=N;i++)
	{
	    int num=i;
	    string t="";
	    while(num!=0)
	    {
	        int r=num%2;
	        t=to_string(r)+t;
	        num=num/2;
	    }
	    res.push_back(t);
	}
	return res;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends