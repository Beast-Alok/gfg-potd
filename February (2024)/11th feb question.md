## 01. Recamans sequence Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/recamans-sequence4856/1)

Level : `Easy`

### My Approach

- This solution uses dynamic programming with memoization (storing intermediate results) to avoid redundant calculations and improve the efficiency of the recursive solution.

- **find method**: This is a recursive function that explores all possible paths from the current cell (x, y) to the destination (n-1, n-1) while keeping track of the remaining sum k. The base cases check whether the current cell is out of bounds, the remaining sum is negative, or if the destination is reached with the required sum.

  -  If the current cell is at the destination and the remaining sum is zero, it increments the count of valid paths by returning 1.
  -  If the result for the current state (x, y, k) is already computed and stored in the dp array, it returns the precomputed result.
  -  Otherwise, it recursively explores paths by moving right (x+1) and down (y+1) while subtracting the value of the current cell from the remaining sum k.

-  **numberOfPath method**: This method initializes a 3D dynamic programming table (dp) with dimensions (n x n x k+1) and sets all values to -1. It then calls the find method with the initial parameters (0, 0, k, dp) to find the total number of paths.

-  **main function**: In the main function, an object of the Solution class is created (obj). It reads the number of test cases (t), and for each test case, it reads the grid size (n), the target sum (k), and the values in the grid (v). It then calls numberOfPath and prints the result for each test case.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n)
- **Auxiliary Space Complexity** : O(n)

### Code (C++)
```cpp
class Solution{
public:
    vector<int> recamanSequence(int n){
        int arr[1000000] = {0};
        vector<int> v;
        for(int i=0; i<n; i++){
            if(i==0){
                v.push_back(0);
                arr[0]++;
            }
            else{
                int x = v[i-1]-i;
                if(x<0){
                    int y = v[i-1]+i;
                    v.push_back(y);
                    arr[y]++;
                }
                else{
                    if(arr[x]!=0){
                        int k = v[i-1]+i;
                        v.push_back(k);
                        arr[k]++;
                    }
                    else{
                        v.push_back(x);
                        arr[x]++;
                    }
                }
            }
        }
        return v;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.