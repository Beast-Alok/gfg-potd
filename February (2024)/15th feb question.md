## 01. Count all Possible Path Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/castle-run3644/1)

Level : `Medium`

### My Approach

**cloneGraph Method**:

- It contains a single method `isPossible` that takes a 2D vector (`paths`) as an argument.
- The method iterates over each sub-vector in `paths` and checks if the sum of its elements is even. If any sub-vector has an odd sum, the function returns `false`. Otherwise, if all sub-vectors have even sums, it returns `true`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N^2)
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution {
public:
    int isPossible(vector<vector<int>> paths){
        for(auto i: paths){
            if(accumulate(i.begin(), i.end(), 0) % 2 != 0)
                return false;
        }
        return true;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.