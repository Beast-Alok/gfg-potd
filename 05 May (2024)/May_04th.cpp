//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
Node* solve(int* in, int* post, int n, int inLow, int inHigh, int postLow, int postHigh) {
        if(inLow > inHigh) return NULL;
        int x = post[postHigh];
        int rootInd = -1;
        
        for(int i = 0; i < n; i++) {
            if(x == in[i]) {
                rootInd = i;
                break;
            }
        }
        
        int leftCount = rootInd - inLow;
        int rightCount = inHigh - rootInd - 1;
        
        int leftInLow = inLow, leftInHigh = rootInd - 1;
        int rightInLow = rootInd + 1, rightInHigh = inHigh;
        int leftPostLow = postLow, leftPostHigh = postLow + leftCount - 1;
        int rightPostLow = leftPostHigh + 1, rightPostHigh = postHigh - 1;
        
        Node* root = new Node(x);
        root->left = solve(in, post, n, leftInLow, leftInHigh, leftPostLow, leftPostHigh);
        root->right = solve(in, post, n, rightInLow, rightInHigh, rightPostLow, rightPostHigh);
        
        return root;
    }
    
public:
    Node* buildTree(int in[], int post[], int n) {
        return solve(in, post, n, 0, n - 1, 0, n - 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
