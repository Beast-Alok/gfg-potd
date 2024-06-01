## 01. Distribute candies in a binary tree Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1)

Level : `Hard`

### My Approach
- I solved this problem by a recursive depth-first traversal of the binary tree.
- This function takes a `Node* root` and a reference to an `int num_moves`.
- The base case checks if the current node is `nullptr` (indicating an empty subtree). If so, it returns 0.
- The function then recursively calls itself on the `left` and `right` children of the current node and stores the return values in `left` and `right`.
- The total number of moves for the current subtree is updated by adding the absolute values of `left` and `right` to `num_moves`. This accounts for the moves needed to distribute candies within the current subtree.
- The function returns the total number of candies needed for the current subtree, which is the sum of the current node's key, `left`, and `right`, minus 1.
### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N)
- **Auxiliary Space Complexity** : O(height of the tree)

### Code (C++)
```cpp
class Solution{
public:
    int distribute_helper(Node* root,int& num_moves)
    {
        if(!root)
        return 0;
        
        int left=distribute_helper(root->left,num_moves);
        int right=distribute_helper(root->right,num_moves);
        
        num_moves+=abs(left)+abs(right);
        
        return root->key+left+right-1;
    }
    int distributeCandy(Node* root)
    {
        int num_moves=0;
        int call=distribute_helper(root,num_moves);
        return num_moves;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.