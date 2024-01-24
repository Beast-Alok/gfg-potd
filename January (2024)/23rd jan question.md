## 01. Course Schedule Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/course-schedule/1)

Level : `Medium`

### My Approach
- **Data Structures**:
The class uses a vector inDegree to store the in-degrees of each node. This is initialized with zeros.
It also uses an unordered map adj to represent the adjacency list of the graph, where the key is a course and the associated value is a list of courses that depend on it.

- **Graph Construction**:
In the constructor, the class initializes the in-degrees and constructs the adjacency list based on the prerequisites.
For each prerequisite pair (u, v), it adds v to the adjacency list of u, indicating that u must be taken before v. It also increments the in-degree of v.

- **Topological Ordering using BFS**:
The findOrder method performs a Breadth-First Search (BFS) to find a topological ordering of the courses.
It starts by enqueueing all nodes with in-degree 0 into a queue (q).
For each node dequeued, it adds the node to the result vector ans and decreases the in-degrees of its neighbors.
If the in-degree of a neighbor becomes 0, it is enqueued since it can now be taken.

- **Validity Check**:
After the BFS loop, if the size of the result vector (ans) is not equal to the total number of nodes (n), it means there is no valid ordering.
In such a case, an empty vector is returned to indicate that no ordering is possible.

- **Returning the Result**:
If the size of the result vector is equal to n, it means a valid ordering was found, and the result vector is returned.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N+M)
- **Auxiliary Space Complexity** : O(N+M)

### Code (C++)
```cpp
class Solution{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> inDegree(n, 0);
        unordered_map<int, list<int>> adj;
        
        for(int i=0; i<m; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
            inDegree[u]++;
        }
        
        queue<int> q;
        vector<int> ans;
        
        bool found = false;
        for(int i=0; i<n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                found = true;
            }
        }
        
        if(!found) {
            return ans;
        }
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto nbr: adj[node]) {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        if(ans.size() != n) {
            return {};
        }
        return ans;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.