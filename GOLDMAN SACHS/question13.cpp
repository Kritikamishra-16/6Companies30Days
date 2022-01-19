// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<pair<int,string>> st;
         int curr_num=0,prev_num=0;
         string prev_str="",curr_str="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' and s[i]<='9')
            {
                curr_num=curr_num*10+(s[i]-'0');
            }
            else if(s[i]>='a' and s[i]<='z')
            {
                curr_str+=s[i];
            }
            else if(s[i]=='[')
            {
                st.push({curr_num,curr_str});
                curr_num=0;
                curr_str="";
            }
            else if(s[i]==']')
            {
                auto p=st.top();
                st.pop();
                prev_str=p.second;
                prev_num=p.first;
                string temp=curr_str;
                for(int c=1;c<prev_num;c++)
                {
                    curr_str+=temp;
                }
                curr_str=prev_str+curr_str;
            }
            
        }
        return curr_str;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends