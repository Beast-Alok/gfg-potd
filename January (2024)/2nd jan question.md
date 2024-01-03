## 01. Largest Sum Subarray of Size at least K Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1)

Level : `Medium`

### My Approach
I solved this problem by first forming subarray of required number of elements that is `k` and then try to extend subarray if the sum of element is greater then previous sum. Here dp is used in this question.

- First create a vector `dp` of size `n+1` of type `long long` and initialize every element with `0`.
- Now iterate from `n-1 to 0` by iterator `i` and insert the following changes in `dp`.
- Now calculate the current sum of first `k` element from the array `a` by a for loop.(after this step we try to extend the subarray)
- Now iterate from `k to n-1` and find the largest sum of the subarray by extending it further than `k` elements and record the higest sum.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n), where n is the size of the input array.
- **Auxiliary Space Complexity** : O(k), where k is the input parameter.

### Code (C++)
```cpp
class Solution {
  public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        vector <long long> dp(n+1, 0);
        for (int i = n-1; i >= 0; i--)
        {
            dp[i] = a[i] + dp[i+1];
            dp[i] = max(dp[i], 0LL);
        }

        long long ans = -1e18;
        long long cur_sum = 0;
        for (int i = 0; i < k; i++)
        {
            cur_sum += a[i];
        }

        for (int i = k; i < n; i++)
        {
            long long sum = cur_sum + dp[i];
            ans = max(ans, sum);

            cur_sum += a[i];
            cur_sum -= a[i-k];
        }
        return max(ans, cur_sum);
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.