## 01. Paths from root with a specified sum Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/paths-from-root-with-a-specified-sum/1)

Level : `Medium`

### My Approach
- The private function `helper` is a recursive function that explores all paths in the binary tree, starting from the root. It keeps track of the current path in the `temp` vector and checks whether the sum of node values in the path equals the target sum. If it does, the path is added to the result (`res`).
- The function recursively explores the left and right subtrees, updating the current sum along the way. After exploring a path or subtree, the last node is removed from the `temp` vector to backtrack.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N)
- **Auxiliary Space Complexity** : O(N^2)

### Code (C++)
```cpp
class Solution{
private:
    vector<int> temp;
    vector<vector<int>> res;
    void helper(Node * root, int sum){
        if(!root) return ;
        
        temp.push_back(root->key);
        
        if(sum - root->key == 0) res.push_back(temp);
        helper(root->left,sum-root->key);
        helper(root->right,sum-root->key);
        
        temp.pop_back();
        
    }
public:
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        helper(root,sum);
        return res;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.