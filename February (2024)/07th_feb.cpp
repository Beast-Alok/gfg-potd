#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
// gff solution from here
class Solution{
    public:
    void traverse(Node *root, unordered_map<int, vector<int>> &adj, unordered_map<int, int> &distance){
        if(root == nullptr) return;
        distance[root->data] = INT_MAX;
        if(root->left){
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
        }
        if(root->right){
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
        }
        traverse(root->left, adj, distance);
        traverse(root->right, adj, distance);
    }
    int findDist(Node* root, int a, int b) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> distance;
        traverse(root, adj, distance);
        distance[a] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, a});
        while(!pq.empty()){
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for(int const &newNode: adj[currNode]){
                if(1 + currDist < distance[newNode]){
                    distance[newNode] = 1 + currDist;
                    pq.push({(1+currDist), newNode});
                }
            }
        }
        return distance[b];
    }
};

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// code written by alok kumar raghuwanshi