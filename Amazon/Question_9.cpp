// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        unordered_map<string,int> row_m;
        unordered_map<string,int> col_m;
        unordered_map<string,int> box_m;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(mat[i][j]==0)
                continue;
                string r="R"+to_string(i)+to_string(mat[i][j]);
                string c="C"+to_string(j)+to_string(mat[i][j]);
                int b=(i/3)*3+(j/3);
                string box="Box"+to_string(b)+to_string(mat[i][j]);
                
                row_m[r]++;
                col_m[c]++;
                box_m[box]++;
                
                if(row_m[r]>1||col_m[c]>1||box_m[box]>1)
                return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends