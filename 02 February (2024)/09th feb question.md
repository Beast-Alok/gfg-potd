## 01. Check for Children Sum Property in a Binary Tree Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/children-sum-parent/1)

Level : `Medium`

### My Approach

**Base Case**:

-  If the current node is NULL or a leaf node (both left and right children are NULL), return 1 (indicating that the children sum property holds true for this node).

**Sum Calculation**:

-  Calculate the sum of the data values of the left and right children, if they exist.

**Property Check**:

-  Check if the sum of the left and right children's data is equal to the data of the current node.
-  Also, recursively check if the children sum property holds true for the left and right subtrees.

**Return Result**:

-  If all conditions are satisfied, return 1 (indicating that the children sum property holds true for the current node and its descendants). Otherwise, return 0.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n)
- **Auxiliary Space Complexity** : O(Height of the Tree)

### Code (C++)
```cpp
class Solution{
    public:
    int isSumProperty(Node *root)
    {
     if((root==NULL)||(root->left==NULL && root->right==NULL))return 1;

      int sum=0;

      if(root->left!=NULL) sum +=root->left->data;

      if(root->right!=NULL)sum+=root->right->data;

      return (root->data==sum && isSumProperty(root->left) &&isSumProperty(root->right));
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.