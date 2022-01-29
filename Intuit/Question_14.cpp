class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        if(q.size()==0 || q.size()==(n*n))
            return -1; //NO 1's or lands in the grid
        int level=-1;
        int dir[4][4]={{0,1},{1,0},{-1,0},{0,-1}};
        while(q.size()!=0)
        {
            level++;
            int curr_size=q.size();
            while(curr_size--)
            {
                auto p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int row=p.first+dir[i][0];
                    int col=p.second+dir[i][1];
                    if(row<0|| col<0 || row>=n || col>=n || vis[row][col]==1)
                        continue;
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        return level;
    }
};