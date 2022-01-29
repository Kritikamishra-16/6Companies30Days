class Solution {
public:
    bool isValid(int mx,vector<int> &nums,int m)
    {
        int count=1,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mx)
            {
                count+=1;
                sum=nums[i];
                if(sum>nums[i])
                    return false;
            }
        }
        if(count<=m)
            return true;
        return false;
    }
    int splitArray(vector<int>& nums, int m) {
        int start=INT_MIN,end=0,res;
        for(int i=0;i<nums.size();i++)
        {
            end+=nums[i];
            start=max(start,nums[i]);
        }
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isValid(mid,nums,m))
            {
                end=mid-1;
                res=mid;
            }
            else{
                start=mid+1;
            }
        }
        return res;
    }
};