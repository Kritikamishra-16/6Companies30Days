// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        int num=0;
        string str="";
        stack<int> st;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='D')
            {
                num+=1;
                st.push(num);
            }
            else if(S[i]=='I')
            {
                num+=1;
                st.push(num);
                while(!st.empty())
                {
                    str+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num+1);
        while(!st.empty())
        {
            str+=to_string(st.top());
            st.pop();
        }
        return str;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends