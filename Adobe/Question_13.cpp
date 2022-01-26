// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int LIS(vector<int> &a)
    {
        vector<int> res;
        if(a.size()>0)
        res.push_back(a[0]);
        for(int i=1;i<a.size();i++)
        {
            if(a[i]>res.back())
            {
                res.push_back(a[i]);
            }
            else{
                int idx=lower_bound(res.begin(),res.end(),a[i])-res.begin();
                res[idx]=a[i];
            }
        }
        return res.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> a;
        for(int i=0;i<N;i++)
        {
            if(binary_search(B,B+M,A[i]))
            {
                //vector a contains only those elements which are present in B
                a.push_back(A[i]);
            }
        }
        int lis=LIS(a);
        int deletion=N-lis;
        int insertion=M-lis;
        return (deletion +insertion);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
