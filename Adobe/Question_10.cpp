// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        vector<string> res;
        int mx=0;
        string s1,s2;
        for(auto s:mp)
        {
            //cout<<s.first<<" "<<s.second<<endl;
            if(mx<s.second)
            {
                s1=s.first;
                s2=to_string(s.second);
                mx=s.second;
            }
        }
      //  cout<<endl;
        res.push_back(s1);
        res.push_back(s2);
        return res;
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
