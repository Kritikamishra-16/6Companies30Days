// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int l1=0,l2=c-1,r1=0,r2=r-1;
        vector<int> res;
        int dir=0;
        while(r1<=r2 and l1<=l2)
        {
            //r1 traversal
            if(dir==0)
            {
            for(int j=l1;j<=l2;j++)
            {
             
                res.push_back(matrix[r1][j]);
            }
            r1++;
            }
            //l2 traversal
            else if(dir==1)
            {
            for(int i=r1;i<=r2;i++)
            {
                res.push_back(matrix[i][l2]);
            }
            l2--;
            }
            //r2 traversal
            else if(dir==2)
            {
            for(int j=l2;j>=l1;j--)
            {
                res.push_back(matrix[r2][j]);
            }
            r2--;
            }
            //l1 traversal
            else if(dir==3)
            {
            for(int i=r2;i>=r1;i--)
            {
                res.push_back(matrix[i][l1]);
            }
            l1++;
            }
            dir=(dir+1)%4;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends