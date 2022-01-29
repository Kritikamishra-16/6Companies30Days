class Solution {
public:
    int f1=0,f2=0;
    void visited(vector<vector<int>> &height,int i,int j,int m,int n,vector<vector<int>> &vis,int prev)
    {
        //base case
        if(i<0 || j<0 || i>=m || j>=n)
            return;
        if(vis[i][j]==1 || height[i][j]<prev)
            return;
        vis[i][j]=1;
        visited(height,i-1,j,m,n,vis,height[i][j]);
        visited(height,i+1,j,m,n,vis,height[i][j]);
        visited(height,i,j-1,m,n,vis,height[i][j]);
        visited(height,i,j+1,m,n,vis,height[i][j]);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> vis1(m,vector<int>(n,0));
        vector<vector<int>> vis2(m,vector<int>(n,0));
        //from top and left edge ->pacific ocean
        for(int i=0;i<m;i++)
        {
            visited(heights,i,0,m,n,vis1,-1);
        }
        for(int j=0;j<n;j++)
        {
            visited(heights,0,j,m,n,vis1,-1);
        }
        
        //from bottom and right edge ->atlantic ocean
        for(int i=0;i<m;i++)
        {
            visited(heights,i,n-1,m,n,vis2,-1);
        }
        for(int j=0;j<n;j++)
        {
            visited(heights,m-1,j,m,n,vis2,-1);
        }
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis1[i][j] and vis2[i][j])
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};