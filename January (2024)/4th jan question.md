## 01. Find element occuring once when all other are present thrice Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1)

Level : `Medium`

### My Approach
I solved this problem using unordered map to calculate frequency of each number.

- First create a unordered map `f` as per the code.
- Now just store every value of array into unordered map using for loop.
- Now iterate over unordered map `f` and return the value whose frequency is equal to one.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N), where N is the number of elements present in the array.
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        map<int,int> f;
        for(int i = 0; i < N; i++){
            ++f[arr[i]];
        }
        for (const auto& pair : f) {
            if (pair.second == 1)
            {
                return pair.first;
            }
        }
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.