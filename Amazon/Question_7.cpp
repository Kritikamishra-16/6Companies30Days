// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string res="";
		    list<char> l;
		    unordered_map<char,int> mp;
		    for(int i=0;i<A.size();i++)
		    {
		        mp[A[i]]++;
		        if(mp[A[i]]==1)
		        {
		            l.push_back(A[i]);
		        }
		        else{
		            l.remove(A[i]);
		        }
		        if(l.size()>0)
		        {
		            res+=l.front();
		        }
		        else{
		            res+="#";
		        }
		        
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends