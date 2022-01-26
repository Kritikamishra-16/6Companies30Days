// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n==1||n==2)   //if only one number is present 
        {                //if only two numbers are present in array
            return n;
        }
        vector<unordered_map<int,int>> dp(n);
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int diff=A[i]-A[j];
                if(dp[j].find(diff)!=dp[j].end())
                {
                    dp[i][diff]=dp[j][diff]+1;
                }
                else{
                    dp[i][diff]=1;    
                }
                mx=max(dp[i][diff],mx);
            }
        }
        return mx+1;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
