// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> res;
        list<int> l;
        int i=0,j=0;
        while(j<n)
        {
            while(l.size()!=0 and arr[j]>l.back())
            {
                l.pop_back();
            }
            l.push_back(arr[j]);
            if((j-i+1)<k)
            {
                j+=1;
            }
            else if((j-i+1)==k) //window size hit
            {
                res.push_back(l.front());
                if(l.front()==arr[i])
                {
                    i+=1;
                    l.pop_front();
                }
                else{
                    i+=1;
                }
                j+=1;
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends