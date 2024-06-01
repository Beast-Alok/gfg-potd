## 01. Min distance between two given nodes of a Binary Tree Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1)

Level : `Medium`

### My Approach

**Traversal and Adjacency List Construction**:

-  The traverse function is responsible for traversing the binary tree and creating an adjacency list.
-  The adjacency list is represented using an unordered map (adj), where each node's data is mapped to a vector containing its adjacent nodes.
-  The function also initializes a distance map (distance) with INT_MAX for each node.

**Dijkstra's Algorithm for Shortest Path**:

-  The findDist function utilizes Dijkstra's algorithm to find the shortest path between two nodes in the binary tree.
-  A priority queue (pq) is used to process nodes based on their distances.
-  The algorithm starts with the source node (a) and initializes its distance to 0 in the distance map.
-  Nodes are continually extracted from the priority queue, and their neighbors are updated if a shorter path is found.
-  The priority queue contains pairs of (distance, node) to prioritize nodes based on their distances.

**Priority Queue and Relaxation**:

-  The priority queue is initialized with the source node (a) having a distance of 0.
-  While the priority queue is not empty, nodes are extracted, and their neighbors are relaxed (updated if a shorter path is found).
-  Relaxation is achieved by comparing the current distance to a node (currDist) plus the edge weight to its neighbor.

**Result**:

-  The final result is the distance between the two given nodes (a and b), which is retrieved from the distance map.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n)
- **Auxiliary Space Complexity** : O(Height of the Tree)

### Code (C++)
```cpp
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

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.