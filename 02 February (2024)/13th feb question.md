## 01. Clone an Undirected Graph Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/clone-graph/1)

Level : `Medium`

### My Approach

**cloneGraph Method**:

- Input Handling: The method takes a single argument, which is a pointer to the original graph's root node (Node* node).
- Base Case: If the input node is NULL, the method returns NULL, indicating that the cloned graph for this node is also NULL.
- Cloning with Memoization:
  -  The method uses an unordered map named copies to store the mapping between the original nodes and their corresponding cloned nodes.
  -  If the current node is not present in the copies map, a new node is created with the same value as the original node (copies[node] = new Node(node->val, {});).
  -  The neighbors of the original node are then cloned recursively, and the cloned neighbors are added to the neighbors vector of the newly created node.
- Return Cloned Node:Finally, the method returns the cloned node corresponding to the input original node (return copies[node];).

**Memoization (Use of copies Map)**:

- The purpose of using the copies map is to ensure that each node in the original graph is only cloned once. It helps in avoiding redundant work by storing previously cloned nodes and their relationships.
- If a node has already been cloned (present in the copies map), the method directly returns the corresponding cloned node, preventing the need for redundant cloning.
- The memoization technique significantly improves the efficiency of the cloning process, especially when the graph has cycles or repeated nodes.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n + m)
- **Auxiliary Space Complexity** : O(n)

### Code (C++)
```cpp
class Solution {
public:
    // Function to clone a graph
    Node* cloneGraph(Node* node) {
        // If the node is NULL, return NULL
        if (!node) {
            return NULL;
        }
        // If the node is not present in the map, create a copy of it
        if (copies.find(node) == copies.end()) {
            // Create a new node with the same value as the original node
            copies[node] = new Node(node -> val, {});
            // Copy the neighbors of the original node recursively
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        // Return the copy of the node
        return copies[node];
    }
private:
    // Map to store the copy of the nodes
    unordered_map<Node*, Node*> copies;
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.