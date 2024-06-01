## 01. All Unique Permutations of an array Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1)

Level : `Medium`

### My Approach
I solved this problem by using `next_permutation` function.
- First sorts the array in ascending order to get permutations in lexicographically non-decreasing order.
- Then store all the possible permutation combination into `res` vector.
- Continue to store all the permutation in the `res` vector untill  all permutations are exhausted. This is done using `next_permutation` function.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n*n!)
- **Auxiliary Space Complexity** : O(n*n!)

### Code (C++)
```cpp
class Solution{
public:
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        do {
            res.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));

        return res;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.