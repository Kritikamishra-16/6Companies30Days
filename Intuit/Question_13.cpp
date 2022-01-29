class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> t; //for trailing zeroes
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                {
                    count+=1;
                }
                else{
                    break;
                }
            }
            t.push_back(count);
           
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            int trail_zero_req=n-(i+1);
           // find nearest row which fullfill our zeroes requirement
            int curr=i;
            while(curr<n and t[curr]<trail_zero_req)
            {
                curr++;
            }
            if(curr==n)
                return -1;
            
            res+=(curr-i);
            //push down all the trailing zeroes between swap rows
            int c=t[curr];
           while(curr>0)
           {
               t[curr]=t[curr-1];
               curr--;
           }
           t[curr]=c; 
        }
        return res;
    }
};