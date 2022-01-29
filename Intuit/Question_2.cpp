// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int f=0;
    void solve(vector<vector<char>>& board,int i,int j,string word,int idx,
    vector<vector<int>> &visited)
    {
        //base case
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
        return;
        if(visited[i][j]==1 || board[i][j]!=word[idx])
        return;
        if(board[i][j]==word[idx])
        {
            visited[i][j]=1;
            if(idx==word.size()-1)
            {
                f=1;
                return;
            }
            solve(board,i-1,j,word,idx+1,visited);
            solve(board,i+1,j,word,idx+1,visited);
            solve(board,i,j-1,word,idx+1,visited);
            solve(board,i,j+1,word,idx+1,visited);
        }
        //backtrack 
        //change the visited back for other searches
        visited[i][j]=0;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size(),m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0] and visited[i][j]==0)
                {
                    solve(board,i,j,word,0,visited);
                }
                if(f)
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends