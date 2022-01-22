// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    map<char,int> mp;
	    mp['!']=1;
	    mp['#']=2;
	    mp['$']=3;
	    mp['%']=4;
	    mp['&']=5;
	    mp['*']=6;
	    mp['@']=7;
	    mp['^']=8;
	    mp['~']=9;
	    int i=0,j,f=0;
	    for(auto x:mp)
	    {
	        j=i;
	        f=0;
	        while(j<n)
	        {
	            if(nuts[j]==x.first)
	            {
	                swap(nuts[i],nuts[j]);
	                f=1;
	                break;
	            }
	            j+=1;
	        }
	        if(f)
	        i+=1;
	    }
	    for(int k=0;k<n;k+=1)
	    {
	        bolts[k]=nuts[k];
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends