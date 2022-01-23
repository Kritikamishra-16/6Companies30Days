// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void solve(vector<vector<int>>& grid,int i,int j,int n,int m,int &res,vector<vector<int>> &visited)
    {
        //base case
        if(i<0 || j<0 ||i>=n||j>=m||grid[i][j]==0||visited[i][j]==1)
        return;
        visited[i][j]=1;
        res+=1;
        solve(grid,i-1,j,n,m,res,visited);
        solve(grid,i+1,j,n,m,res,visited);
        solve(grid,i,j-1,n,m,res,visited);
        solve(grid,i,j+1,n,m,res,visited);
        solve(grid,i-1,j-1,n,m,res,visited);
        solve(grid,i+1,j+1,n,m,res,visited);
        solve(grid,i-1,j+1,n,m,res,visited);
        solve(grid,i+1,j-1,n,m,res,visited);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int res=0,count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 and visited[i][j]==0)
                {
                count=0;
                solve(grid,i,j,n,m,count,visited);
                }
                res=max(res,count);
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends