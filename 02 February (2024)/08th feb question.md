## 01. Check if all leaves are at same level Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/leaf-at-same-level/1)

Level : `Easy`

### My Approach

**Base Cases in f function**:

-  If the current node is NULL (i.e., the tree is empty), return true.
-  If the current node is a leaf node (both left and right children are NULL), check if the depth (height) matches the previously recorded maximum depth (prevDepth). If prevDepth is -1, set it to the current depth and return true (indicating the first leaf node encountered). If prevDepth is not -1, check if the current depth matches prevDepth and return true if it does, indicating that the leaf node is at the same level. Otherwise, return false.

**Recursive Calls**:

-  Recursively call the function f on the left and right children of the current node, incrementing the height by 1 in each recursive call.
-  If either the left or right subtree returns false, propagate the false result up the recursive calls.

**Overall Logic**:

-  The check function initializes maxDepth to -1, indicating that no leaf node has been encountered yet.
-  It calls the f function with the root of the tree, height initialized to 0, and maxDepth to keep track of the maximum depth encountered so far.
-  The result of the f function is returned by the check function.

**Output**:

-  The check function returns true if all leaf nodes are at the same level; otherwise, it returns false.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n)
- **Auxiliary Space Complexity** : O(Height of the Tree)

### Code (C++)
```cpp
class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        int maxDepth=-1;
        return f(root,0,maxDepth);
        
    }
    bool f(Node * root,int height,int &prevDepth){
        if(!root) return true;
        if(!root->left and !root->right){
            if(prevDepth==-1){
                prevDepth=height;
                return true;
            }
            else if(prevDepth==height) return true;
            return false;
        }
        if(f(root->left,height+1,prevDepth)==false) return false;
        if(f(root->right,height+1,prevDepth)==false) return false;
        return true;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.