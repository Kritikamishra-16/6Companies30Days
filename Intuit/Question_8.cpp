class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size()==1)
            return 0;
        int res=0;
        for(int i=0;i<points.size();i++)
        {
            map<int,int> mp;
            for(int j=0;j<points.size();j++)
            {
                if(i==j)
                    continue;
                int x=pow(points[j][0]-points[i][0],2);
                int y=pow(points[j][1]-points[i][1],2);
                int d=x+y;
                mp[d]++;
            }
            for(auto x: mp)
            {
                if(x.second>=2)
                {
                    res+=(x.second)*(x.second-1);
                }
            }
        }
        return res;
        
    }
};