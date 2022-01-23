// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(vector<int> adj[],vector<int> &visited,int src,int c,int d)
    {
        visited[src]=1;
        for(auto x:adj[src])
        {
            if( (src==c and x==d) || (src==d and x==c))
            continue;
            if(!visited[x])
            {
                dfs(adj,visited,x,c,d);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> visited(V,0);
        dfs(adj,visited,c,c,d);
        if(visited[d])
        return 0;
        else
        return 1;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends