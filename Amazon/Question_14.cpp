// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int max_time=0;
    void burn_tree(Node *root,Node *blocked,int t)
    {
        if(!root || root==blocked)
        return;
        if(max_time<t)
        {
            max_time=t;
        }
        burn_tree(root->left,blocked,t+1);
        burn_tree(root->right,blocked,t+1);
    }
    int burning_tree(Node *root,int target)
    {
        if(!root)
        return -1;
        //if burning node is found then set the burning node subtree on fire and find maxtime
        if(root->data==target)
        {
            //starting node ,blocked node=null,starting time=0
            //as this is the 1stburning node blocked node->null
            burn_tree(root,NULL,0);
            return 1;
        }
        
        int left_time=burning_tree(root->left,target);
        if(left_time!=-1) //left tree burn ho chuka hai
        {
            burn_tree(root,root->left,left_time);
            return left_time+1;
        }
        int right_time=burning_tree(root->right,target);
        if(right_time!=-1) //right tree burn ho chuka hai
        {                  //blocked node
            burn_tree(root,root->right,right_time);
            return right_time+1;
        }
        
        return -1;
    }
    int minTime(Node* root, int target) 
    {
        //first find root to node(burning) path
        burning_tree(root,target);
        return max_time;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends