// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    class element{
        public:
        int value;
        int index;
        int row;
        //constructor
        element(int val,int idx,int row_num)
        {
            value=val;
            index=idx;
            row=row_num;
        }
    };
    //comparator
    struct comp{
        bool operator()(element a,element b)
        {
            return a.value>b.value;
        }
    };
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<element,vector<element>,comp> pq;
        pair<int,int> res;
        int mx=INT_MIN,range=INT_MAX;
        for(int i=0;i<k;i++)
        {
            element e(KSortedArray[i][0],0,i);
            pq.push(e);
            mx=max(mx,KSortedArray[i][0]);
        }
        while(pq.size()==k)
        {
            element x=pq.top();
            pq.pop();
            int current_range=(mx-x.value);
            if(range>current_range)
            {
                range=current_range;
                //cout<<current_range<<endl;
                res=make_pair(x.value,mx);
            }
            if(x.index==n-1)
            break;
            pq.push(element(KSortedArray[x.row][x.index+1],x.index+1,x.row));
            mx=max(mx,KSortedArray[x.row][x.index+1]);
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
