## 01. Check if a given graph is tree or not Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/is-it-a-tree/1)

Level : `Medium`

### My Approach
- **Condition Check for Tree**:
The isTree function begins by checking a necessary condition for a graph to be a tree: the difference between the number of nodes (n) and the number of edges (m) should be 1. If this condition is not met, the graph cannot be a tree, and the function immediately returns 0.

- **Graph Representation**:
An adjacency list (adj) is used to represent the graph. The edges provided in the input are used to construct this adjacency list.

- **DFS Traversal**:
The class defines a dfs function for performing a depth-first search on the graph starting from a given node.
The DFS traversal marks nodes as visited, preventing infinite loops and ensuring all connected nodes are explored.

- **DFS Call**:
The dfs function is called starting from the first node (node 0) of the graph.
All reachable nodes from the starting node are marked as visited.

- **Check for Disconnected Components**:
After DFS, the code checks if there are any unvisited nodes. If there are unvisited nodes, it indicates the presence of disconnected components in the graph.
In such a case, the graph is not a tree, and the function returns 0.

- **Return Result**:
If all nodes are visited and the necessary condition is satisfied, the graph is considered a tree, and the function returns 1.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N+M)
- **Auxiliary Space Complexity** : O(N)

### Code (C++)
```cpp
class Solution{
public:
    void dfs(vector<int>* adj,int node,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfs(adj,it,visited);
        }
    }
    int isTree(int n, int m, vector<vector<int>> &edg) {
        
        if((n-m)!=1)
        return 0;
        
        vector<int> adj[n];
        for(auto it:edg)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        dfs(adj,0,visited);
        
        for(auto it:visited)
        {
            if(it==0)
            return 0;
        }
        return 1;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.