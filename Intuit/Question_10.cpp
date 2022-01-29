class Solution {
public:
    void dfs(vector<int> adj[],int src,vector<int> &visited)
    {
        visited[src]=1;
        for(auto x:adj[src])
        {
            if(!visited[x])
            {
                dfs(adj,x,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> v[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(isConnected[i][j]==1)
                v[i].push_back(j);
            }
        }
       vector<int> visited(n,0);
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                dfs(v,i,visited);
                res+=1;
            }
        }
        return res;
    }
};