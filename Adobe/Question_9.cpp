// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        int n=N.size(),mid=n/2,p1=mid-1,f=0,idx1,idx2;
        string s1,s2;
        for(int i=p1-1;i>=0;i--)
        {
            if(N[i]<N[i+1])
            {
                f=1;
                idx1=i;
                break;
            }
        }
        if(f)
        {
            for(int i=p1;i>=0;i--)
            {
                if(N[i]>N[idx1])
                {
                    idx2=i;
                    break;
                }
            }
            swap(N[idx1],N[idx2]);
            s1=N.substr(0,p1+1);
            reverse(s1.begin()+idx1+1,s1.end());
            s2=s1;
            reverse(s2.begin(),s2.end());
            if(n%2!=0)
            {
                s1+=N[mid];
            }
            s1+=s2;
        }
        if(f==0)
        {
            return "-1";
        }
        return s1;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
