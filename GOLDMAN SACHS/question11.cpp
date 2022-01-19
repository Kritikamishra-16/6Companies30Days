// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *res=new int[2];
        int visited[n+1];
        for(int i=1;i<n+1;i++)
        {
            visited[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(visited[arr[i]]==1)
            {
                res[0]=arr[i];
            }
            else{
                visited[arr[i]]=1;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            if(visited[i]==0)
            {
                res[1]=i;
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends