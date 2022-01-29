class Solution {
public:
    bool isValid(int mx,vector<int> &weights,int days)
    {
        int d=1,sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            if(sum>mx)
            {
                d+=1;
                sum=weights[i];
                if(sum>mx)
                    return false;
            }
        }
        if(d<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=INT_MIN,end=0,res;
        for(int i=0;i<weights.size();i++)
        {
            end+=weights[i];
            start=max(start,weights[i]);
        }
        //cout<<end;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isValid(mid,weights,days))
            {
                res=mid;
                end=mid-1;  //try to minimize the result
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
};