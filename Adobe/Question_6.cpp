// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int op,int cl,vector<string> &res,string str)
    {
        if(cl==0 and op==0)
        {
            res.push_back(str);
            return;
        }
        if(op==cl)
        {
            solve(op-1,cl,res,str+"(");
        }
        else
        {
            solve(op,cl-1,res,str+")");
            if(op!=0)
            solve(op-1,cl,res,str+"(");
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int op=n,cl=n;
        vector<string> res;
        solve(op,cl,res,"");
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
