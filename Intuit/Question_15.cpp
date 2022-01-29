class Solution {
public:
    bool isValid(long k,vector<int> &piles,long h)
    {
        long hour=0;
        if(k==0)
            return false;
        for(int i=0;i<piles.size();i++)
        {
            hour+=(int)ceil(piles[i]*1.0/k);
        }
        
        if(hour<=h)
            return true;
        else
            return false;
       
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=0;
        int end=0;
        int res=-1;
        for(int i=0;i<piles.size();i++)
        {
            end=max(end,piles[i]);
        }
        while(start<=end)
        {
            long mid=start+(end-start)/2;
            if(isValid(mid,piles,h))
            {
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
};