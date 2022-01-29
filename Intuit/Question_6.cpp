class Solution {
public:
    int find_PeakElement(MountainArray &arr)
    {
        int start=0;
        int end=arr.length()-1;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(arr.get(mid)>arr.get(mid+1))
                end=mid;
            else
                start=mid+1;
        }
        // At the end of the loop start==end ,it points to the peak 
           // element so Im taking that index value as Peak.
        return start;
    }
    int binary_search(MountainArray &arr,int start,int end,int target)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int k=arr.get(mid);
            if(k==target)
                return mid;
            else if(k>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int binary_search_dec(MountainArray &arr,int start,int end,int target)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int k=arr.get(mid);
            if(k==target)
                return mid;
            else if(k>target)
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak_idx=find_PeakElement(mountainArr);
       int r1= binary_search(mountainArr,0,peak_idx,target);
        if(r1!=-1)
            return r1;
       int r2= binary_search_dec(mountainArr,peak_idx+1,mountainArr.length()-1,target);
        return r2;
    }
};