## 01. Flatten BST to sorted list Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1)

Level : `Medium`

### My Approach

**cloneGraph Method**:

- The `solve` function is a recursive function that traverses the BST in an inorder manner (left-root-right).
- Inside the `solve` function, for each node encountered during the inorder traversal:
  - The left child is set to `nullptr` to break the left link.
  - The right child of the previous node (`prev`) is set to the current node, establishing the right link in the doubly linked list.
  - The `prev` pointer is updated to the current node.
- The flattenBST function initializes a dummy node (`prev`) to maintain the reference to the previous node during the traversal. It then calls the `solve` function to perform the inorder traversal.
- Finally, the function returns the right pointer of the dummy node, which now points to the head of the sorted doubly linked list.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N)
- **Auxiliary Space Complexity** : O(N)

### Code (C++)
```cpp
class Solution
{
public:
    void solve(Node* root, Node* &prev)
    {
        if(root == nullptr)
            return;
        solve(root->left, prev);
        root->left = nullptr;
        prev->right = root;
        prev = root;
        solve(root->right, prev);
    }
    Node *flattenBST(Node *root)
    {
        Node* prev = new Node(0);
        Node* head = prev;
        solve(root, prev);
        return head->right;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.