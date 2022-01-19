// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int l=0,u=0,res=0;
        long long prod=1;
        while(u<n)
        {
            prod*=a[u];
            
            if(prod<k)
            {
                res+=(u-l)+1;
                u++;
            }
            else if(prod>=k)
            {
                while(prod>=k)
                {
                    prod=prod/a[l];
                    l++;
                }
                if(prod<k)
                {
                    res+=(u-l)+1;
                    u++;
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends