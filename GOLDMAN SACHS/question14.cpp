class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,u=0,sum=0,res=INT_MAX;
        while(u<nums.size())
        {
            sum+=nums[u];
            if(sum<target)
            {
                u++;
            }
            else if(sum>=target)
            {
                while(sum>=target)
                {
                    res=min(res,(u-l+1));
                    sum-=nums[l];
                    l++;
                }
                u+=1;
            }
        }
        if(res==INT_MAX)
            res=0;
        return res;
    }
};