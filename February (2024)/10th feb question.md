## 01. Number of paths in a matrix with k coins Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1)

Level : `Medium`

### My Approach

- This solution uses dynamic programming with memoization (storing intermediate results) to avoid redundant calculations and improve the efficiency of the recursive solution.

- **find method**: This is a recursive function that explores all possible paths from the current cell (x, y) to the destination (n-1, n-1) while keeping track of the remaining sum k. The base cases check whether the current cell is out of bounds, the remaining sum is negative, or if the destination is reached with the required sum.

  -  If the current cell is at the destination and the remaining sum is zero, it increments the count of valid paths by returning 1.
  -  If the result for the current state (x, y, k) is already computed and stored in the dp array, it returns the precomputed result.
  -  Otherwise, it recursively explores paths by moving right (x+1) and down (y+1) while subtracting the value of the current cell from the remaining sum k.

-  **numberOfPath method**: This method initializes a 3D dynamic programming table (dp) with dimensions (n x n x k+1) and sets all values to -1. It then calls the find method with the initial parameters (0, 0, k, dp) to find the total number of paths.

-  **main function**: In the main function, an object of the Solution class is created (obj). It reads the number of test cases (t), and for each test case, it reads the grid size (n), the target sum (k), and the values in the grid (v). It then calls numberOfPath and prints the result for each test case.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n*n*k)
- **Auxiliary Space Complexity** : O(n*n*k)

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