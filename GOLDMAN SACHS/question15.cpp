// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:         //MAINTAIN MAP FOR FREQUENCY COUNT 
    bool canPair(vector<int> nums, int k) {
        if(nums.size()%2!=0)
        return false;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int r=nums[i]%k;
            mp[r]++;
            //cout<<r<<"->"<<mp[r]<<endl;
        }
        for(int i=0;i<nums.size();i++)
        {
            int r1=nums[i]%k;
            if(r1==0 || 2*r1==k)   //why not k/2 ->k/2 valid only for even numbers check input
            {
                if(mp[r1]%2!=0)
                return false;
            }
            else{
                int r2=k-r1;
                if(mp[r1]!=mp[r2])
                {
                    //cout<<mp[r1]<<" "<<mp[r2]<<endl;
                    return false;
                }
            }
            
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends