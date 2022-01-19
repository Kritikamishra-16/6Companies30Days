// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	vector<ull> ugly_num;
	void precompute(int n)
	{
	    ugly_num.push_back(1);
	    ull p2=0,p3=0,p5=0,next_ug;
	    while(ugly_num.size()<n)
	    {
	        ull res1,res2,res3;
	        res1=ugly_num[p2]*2;
	        res2=ugly_num[p3]*3;
	        res3=ugly_num[p5]*5;
	        next_ug=min(res1,min(res2,res3));
	        if(res1==next_ug)
	        p2++;
	        if(res2==next_ug)
	        p3++;
	        if(res3==next_ug)
	        p5++;
	       
	        ugly_num.push_back(next_ug);
	    }
	}
	ull getNthUglyNo(int n) {
	    precompute(n);
	    ull res=ugly_num[n-1];
	    return res;
	    
	    // code here
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends