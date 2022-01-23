// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.

    vector<string> solve(int a[],int N,int idx,string code[])
    {
        if(idx==N)
        {
            vector<string> v;
            v.push_back("");
            return v;
        }
        int first=a[idx];
        string words=code[first];
        vector<string> temp_res=solve(a,N,idx+1,code);
         vector<string> res;
        for(int i=0;i<words.size();i++)
        {
            char ch=words[i];
            for(auto str:temp_res)
            {
                res.push_back(ch+str);
            }
        }
        return res;
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        string code[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int idx=0;
        vector<string> res=solve(a,N,idx,code);
        return res;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends