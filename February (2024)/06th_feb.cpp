#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
    private:
    set<int> getNodes(Node* root, int k, int& result, int& leaves){
        if(root == nullptr) return {};
        if(root -> left == nullptr && root -> right == nullptr) {leaves++; return {0};}
        
        set<int> left  = getNodes(root -> left, k, result,leaves);
        set<int> right = getNodes(root -> right, k, result, leaves);
        
        
        set<int> curSet;
        for(auto it : left) curSet.insert(it+1);
        for(auto it : right) curSet.insert(it+1);
        
        if(curSet.find(k) != curSet.end()) result++;
        
        return curSet;
    }
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
        int result = 0, leaves = 0;
        
        getNodes(root,k,result,leaves);
        
        if(k == 0) return leaves;
        return result;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}

// code written by alok kumar raghuwanshi