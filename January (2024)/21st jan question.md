## 01. Vertex Cover Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/vertex-cover/1)

Level : `Hard`

### My Approach
- The Solution class is defined with private member variables:

- adj: a 2D vector to represent the adjacency matrix of the graph.
The isPossible function is a helper function inside the Solution class. It checks if it's possible to cover all edges using a set of vertices of a given size (mid). It uses a bitmask to represent the set of vertices.

- The vertexCover function takes the number of vertices n and a vector of edges edges. It initializes the adjacency matrix adj based on the given edges.

- The main logic of the code is in the vertexCover function:

- It performs a binary search between 1 and n (the number of vertices).
- For each midpoint (mid), it calls the isPossible function to check if a vertex cover of size mid is possible.
- If possible, it updates the right bound (r); otherwise, it updates the left bound (l).
- The main function (main) takes input for the number of test cases (t), and for each test case, it takes input for the number of vertices (n), the number of edges (m), and the edges themselves. It then calls the vertexCover function for each test case and prints the result.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(M*N^2log(N))
- **Auxiliary Space Complexity** : O(N^2)

### Code (C++)
```cpp
class Solution{
private:
    vector<vector<int>> adj;
    
    bool isPossible(int n, int m, int mid) {
        int set = (1 << mid) - 1;
        int limit = (1 << n);

        while (set < limit) {
            bool vis[n + 1][n + 1] = {0};
            int edgeCovered = 0;

            for (int j = 1, u = 1; j < limit; j = j << 1, u++) {
                if (set & j) {
                    for (int v = 1; v <= n; v++) {
                        if (adj[u][v] && !vis[u][v]) {
                            edgeCovered++;
                            vis[u][v] = 1;
                            vis[v][u] = 1;
                        }
                    }
                }
            }

            if (edgeCovered == m)
                return true;

            int rightMostSetBit = set & -set;
            int val = set + rightMostSetBit;
            set = (((val ^ set) >> 2) / rightMostSetBit) | val;
        }
        return false;
    }
public:
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        int m = edges.size();
        adj.resize(n + 1, vector<int>(n + 1));

        for (auto v : edges) {
            adj[v.first][v.second] = 1;
            adj[v.second][v.first] = 1;
        }

        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (isPossible(n, m, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.