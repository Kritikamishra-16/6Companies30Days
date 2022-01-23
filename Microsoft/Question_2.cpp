// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int node,vector<int> &visited,vector<int> &order,vector<int> adj[])
    {
        visited[node]=1;
        order[node]=1;
        for(auto x:adj[node])
        {
            if(visited[x]==0)
            {
                if(dfs(x,visited,order,adj))   //ek baar bhi cycle detect ho gyi to turant true                                 //
                return true;                   //return kar denge bina aage check kiye but agar
            }                                  //false return  hoga to next adj node ke liye
                                               //check karenge cycle is liye yha se false 
                                               //return ni kara rahe
            
            else if(visited[x]==1 && order[x]==1) //node already exist in this path
            {
                return true;
            }
        }
        order[node]=0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N+1];
	    for(auto x: prerequisites)
	    {
	        adj[x.second].push_back(x.first);
	    }
	    vector<int> visited(N,0);
	    vector<int> order(N,0);
	    for(int i=0;i<N;i++)
	    {
	        if(visited[i]==0)
	        {
	            if(dfs(i,visited,order,adj))
	            return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends