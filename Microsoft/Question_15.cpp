// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
                        //TOPOSORT using DFS
                        
class Solution{
    public:   
    void dfs(int node,vector<int> &visited,vector<int> adj[],list<int> &res)
    {
        visited[node]=1;
        for(auto x:adj[node])
        {
            if(visited[x]==0)
            {
                dfs(x,visited,adj,res);
            }
        }
        res.push_front(node);
        return;
        
    }
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K+1];
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            for(int j=0;j<min(s1.length(),s2.length());j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');   //let s[j]=c (c-'a')=>(69-67)=>2 
                                                           // a->0 b->1 c->2 d->3
                                                           //zero base indexing for graph adj
                    break;
                }
            }
        }
        vector<int> visited(K,0);
        list<int> res;
        for(int i=0;i<K;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,visited,adj,res);
            }
        }
        string result="";
        for(int i=0;i<K;i++)
        {
            result+=(res.front()+'a');
            res.pop_front();
        }
        return result;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends