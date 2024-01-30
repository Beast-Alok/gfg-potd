## 01. LCS of three strings Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1)

Level : `Medium`

### My Approach

- The function `LCSof3` takes three strings (`A`, `B`, and `C`) and their respective lengths (`n1`, `n2`, and `n3`).
- It uses a 3D vector (`dp`) to store the length of the LCS for all possible combinations of substrings of `A`, `B`, and `C`.
- The triple nested loop iterates through each character of the three strings and fills in the DP table based on the LCS conditions.
- If the characters at the current positions in all three strings match, it increments the LCS length using the previous LCS length from the diagonal cell.
- If there's no match, it takes the maximum LCS length from the adjacent cells.
- Finally, the function returns the length of the LCS of the three strings, which is stored in the bottom-right-most cell of the 3D array.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n1*n2*n3)
- **Auxiliary Space Complexity** : O(n1*n2*n3)

### Code (C++)
```cpp
class Solution
{
public:
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
    {
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
        for (int i=1;i<=n1;i++)
        {
            for (int j=1;j<=n2;j++)
            {
                for (int k=1;k<=n3;k++)
                {
                    if (A[i-1]==B[j-1] && B[j-1]==C[k-1])
                    {
                        dp[i][j][k]=1+dp[i-1][j-1][k-1];
                    }
                    else 
                    {
                        dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                    }
                }
            }
        }
        return dp[n1][n2][n3];
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.