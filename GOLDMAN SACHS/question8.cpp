// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    int dp[str.length()];
		    int mod=1000000007;
		    //single character is decoded by only one way
		    if(str[0]=='0')
		    return 0;
		    dp[0]=1;
		    for(int i=1;i<str.length();i++)
		    {
		        //last two strings "00"
		        if(str[i-1]=='0' and str[i]=='0')
		        {
		            dp[i]=0;
		        }
		        else if(str[i-1]=='0' and str[i]!='0')
		        {
		            dp[i]=dp[i-1];
		        }
		        else if(str[i-1]!='0' and str[i]=='0')
		        {
		            if(str[i-1]=='1'||str[i-1]=='2')
		            dp[i]=(i>2?dp[i-2]:1);
		            else
		            dp[i]=0;
		        }
		        else{
		            if(stoi(str.substr(i-1,2))<=26)
		            {
		            //cout<<stoi(str.substr(i-1,2))<<endl;
		            dp[i]=(dp[i-1]+(i>2?dp[i-2]:1))%mod;
		            }
		            else
		            dp[i]=dp[i-1];
		        }
		    }
		  /*  for(int i=0;i<str.length();i++)
		    {
		        cout<<dp[i]<<" ";
		    }*/
		    return dp[str.length()-1];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends