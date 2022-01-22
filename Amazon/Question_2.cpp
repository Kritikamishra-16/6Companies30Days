class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)
            return 0;
        int l=0,p1,p2,j=1;
        while(j<arr.size()-1)
        {
            p1=j-1;
            p2=j+1;
            if(arr[p1]<arr[j] and arr[p2]<arr[j])
            {
                cout<<arr[j];
                while(p1>0 and arr[p1]>arr[p1-1])
                {
                    p1=p1-1;
                }
                while(p2<arr.size()-1 and arr[p2]>arr[p2+1])
                {
                    p2=p2+1;
                }
                l=max(l,(p2-p1+1));
            }
            j+=1;
        }
        
        return l;
    }
};