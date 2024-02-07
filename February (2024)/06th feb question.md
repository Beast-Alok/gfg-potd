## 01. Node at distance Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/node-at-distance/1)

Level : `Medium`

### My Approach

- This approach efficiently explores the binary tree, calculates the distances from leaf nodes for each node, and increments the result counter whenever the target distance k is found in the set of distances. The recursion ensures that the entire tree is traversed, and the counters are appropriately updated.

**Private Function** - `getNodes`:

**Parameters**:
-  root: Pointer to the current node being processed.
-  k: The target distance from leaf nodes.
-  result: Reference to the counter for nodes at distance k from leaf nodes.
-  leaves: Reference to the counter for leaf nodes.

**Return Type**:
-  Returns a set of integers representing distances from leaf nodes for the current node.

**Functionality**:
-  The function is a recursive helper that traverses the binary tree.
-  Base Case: If the current node is a leaf node, it increments the leaves counter and returns a set with a single element 0 (distance from itself).
-  Recursively calls itself on the left and right children, obtaining their distance sets.
-  Combines the sets obtained from the left and right children, incrementing each distance by 1.
-  If the target distance k is found in the combined set, increments the result counter.
-  Returns the combined set for the current node.

**Public Function** - `printKDistantfromLeaf`:

**Parameters**:
-  root: Pointer to the root of the binary tree.
-  k: The target distance from leaf nodes.

**Return Type**:
-  Returns an integer representing the count of nodes at distance k from leaf nodes.

**Functionality**:
-  Initializes variables result and leaves to 0.
-  Calls the private getNodes function with the root, k, result, and leaves.
-  If k is 0, returns the count of leaf nodes (leaves).
-  Otherwise, returns the count of nodes at distance k from leaf nodes (result).

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n)
- **Auxiliary Space Complexity** : O(Height of the Tree)

### Code (C++)
```cpp
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

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.
