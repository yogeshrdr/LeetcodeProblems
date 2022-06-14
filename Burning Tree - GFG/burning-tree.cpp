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
  
  
   void createMap(Node* root, map<Node*, Node*> &NodeToParent) {
       if(root == NULL)
           return;
       
       if(root->left)
           NodeToParent[root->left] = root;
       
       if(root->right)
           NodeToParent[root->right] = root;
       
       
       createMap(root->left, NodeToParent);
       createMap(root->right, NodeToParent);
       NodeToParent[root] == NULL;
   }
 

   Node* findNode(Node* root, int target) {
       if(root == NULL) 
       return NULL;
       
       if(root->data == target)
           return root;
       
       
       Node* left = findNode(root->left, target);
       Node* right =findNode(root->right, target);
       
       if(left == NULL && right == NULL) 
            return NULL;
       
       if(left == NULL && right != NULL) 
            return right;
       
       if(left != NULL && right == NULL) 
            return left;
   }
 


   int Burn(Node* root, int target, map<Node*, Node*> &NodeToParent) {
       
       map<Node*, bool> visited;
       
       queue<Node*> q;
       
       Node* start = findNode(root,target);
       
       int ans;
       
       q.push(start);
       visited[start] = true;
       
       while(!q.empty()) {
           
           bool flag = false;
           int size = q.size();
           
           for(int i = 0; i<size; i++) {
               Node* front = q.front();
               q.pop();
               
               if(front->left && visited[front->left] == false) {
                   flag = true;
                   q.push(front->left);
                   visited[front->left] = true;
               }
           
               if(front->right && visited[front->right] == false) {
                   flag = true;
                   q.push(front->right);
                   visited[front->right] = true;
               }
           
               if(NodeToParent[front] && visited[NodeToParent[front]] == false) {
                   flag = true;
                   q.push(NodeToParent[front]);
                   visited[NodeToParent[front]] = true;
               }
           
           }
           
           if(flag == true) 
               ans++;
           
           
       }
       
       return ans;
   }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
       map<Node* , Node*> NodeToParent;
       createMap(root,NodeToParent);
      
       return Burn(root, target, NodeToParent);
       
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