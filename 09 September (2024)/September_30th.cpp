//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorderTraversal(Node* root, vector<int>& arr){
        if(!root){
            return;
        }
        inorderTraversal(root->left,arr);
        arr.push_back(root->data);
        inorderTraversal(root->right,arr);
    }
    
    vector<int> mergeTwoSortedArray(vector<int> arr1,vector<int> arr2){
        vector<int> temp;
        
        int i=0,j=0;
        
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }else{
                temp.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<arr1.size()){
            temp.push_back(arr1[i]);
            i++;
        }
        while(j<arr2.size()){
            temp.push_back(arr2[j]);
            j++;
        }
        return temp;
    }
    
    
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> arr1;
        vector<int> arr2;
        inorderTraversal(root1,arr1);
        inorderTraversal(root2,arr2);
        
        return mergeTwoSortedArray(arr1,arr2);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends
