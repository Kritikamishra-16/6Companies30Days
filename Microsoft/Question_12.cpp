// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size();
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int p1=j+1,sum1=arr[i]+arr[j],sum2;
                sum2=k-sum1;
                int p2=arr.size()-1;
                while(p1<p2)
                {
                    if(arr[p1]+arr[p2]<sum2)
                    {
                        p1++;
                    }
                    else if(arr[p1]+arr[p2]>sum2)
                    {
                        p2--;
                    }
                    else if(arr[p1]+arr[p2]==sum2)
                    {
                        vector<int> v;
                         v.push_back(arr[i]);
                         v.push_back(arr[j]);
                         v.push_back(arr[p1]);
                         v.push_back(arr[p2]);
                         res.push_back(v);
                         p1++;
                         p2--;
                    }
                }
            }
        }
        set<vector<int>> s;
        for(int i=0;i<res.size();i++)
        {
            s.insert(res[i]);
        }
        res.clear();
        for(auto x:s)
        {
            res.push_back(x);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends