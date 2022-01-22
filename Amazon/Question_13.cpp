class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int max_time=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                q.push(make_pair(make_pair(i,j),0));
            }
        }
        while(q.size()!=0)
        {
            auto p=q.front();
            q.pop();
            int time=p.second;
            max_time=max(max_time,time);
            int i=p.first.first,j=p.first.second;
            if(i-1>=0 and grid[i-1][j]==1)
            {
                grid[i-1][j]=2; //make it rooten and push in the queue
                q.push(make_pair(make_pair(i-1,j),time+1));
            }
            if(i+1<grid.size() and grid[i+1][j]==1)
            {
                grid[i+1][j]=2; //make it rooten and push in the queue
                q.push(make_pair(make_pair(i+1,j),time+1));
            }
            if(j-1>=0 and grid[i][j-1]==1)
            {
                grid[i][j-1]=2; //make it rooten and push in the queue
                q.push(make_pair(make_pair(i,j-1),time+1));
            }
            if(j+1<grid[0].size() and grid[i][j+1]==1)
            {
                grid[i][j+1]=2; //make it rooten and push in the queue
                q.push(make_pair(make_pair(i,j+1),time+1));
            }
            
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return max_time;
    }
};