## 01. Array Pair Sum Divisibility Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1)

Level : `Medium`

### My Approach
I solved this problem by counting the occurrences of each element's remainder when divided by `k`. Then, I checked whether the stored element's remainder is required by other element's remainder to sum up to the `k`.

- First create a map `f` to count the frequency of the remainder of the elemenets present in the vector `nums`.
- Now iterate over vector `numms` with iterator `i`.
- Now get `current_value` and `needed_value` as per the code. (`needed_value` should be between [0,k] so to do that mod(k) is neccessary step)
- Now check whether `needed_value` is present in the map `f` or not
  - If present, than decrease the frequency of `needed_value` from the map `f`.
  - Also check whether the frequency of `needed_value` after decreament is equal to zero or not.
    - If equal to zero than just erase that `needed_value`.
  - If not present in the map than just insert that `needed_value` with frequency intialized with one.
- Now return `true` if size of map is equal to zero or else return `false`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n), where n is the size of the input vector.
- **Auxiliary Space Complexity** : O(k), where k is the input parameter.

### Code (C++)
```cpp
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map <int, int> f;
        for(int i = 0; i<nums.size(); i++){
            int current_value = nums[i] % k;
            int needed_value = (k - current_value) % k;
            
            if(f.count(needed_value)){
                --f[needed_value];
                
                if(f[needed_value] == 0){
                    f.erase(needed_value);
                }
                
            }else{
                ++f[current_value];
            }
        }
        return f.size() == 0;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.