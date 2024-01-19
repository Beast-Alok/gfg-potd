## 01. Top k numbers in a stream Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/top-k-numbers3425/1)

Level : `Medium`

### My Approach
- Takes a vector arr, an integer `N` (size of the array), and an integer `K` as input.
- Initializes an empty vector of vectors `res` to store the result.
- Uses an unordered map `mp` to store the frequency of each element.
- Uses a set of pairs `s` to maintain a sorted order based on frequency (using negative values for sorting in descending order).
- Iterates through each element in the input array:
  - If the element is already in `mp`, its frequency is updated in both `mp` and `s`.
  - If not, it is added to `mp` with a frequency of 1 and added to `s`.
  - Extracts the top `K` elements from `s` and adds them to the current row in the result vector.
- The result vector is returned.
### Time and Auxiliary Space Complexity

- **Time Complexity** : O(N*K)
- **Auxiliary Space Complexity** : O(N)

### Code (C++)
```cpp
class Solution{
public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        set<pair<int, int>> s;
        for(auto i: arr) {
            vector<int> row;
            if(mp[i] > 0)
                s.erase({-mp[i], i});
            mp[i]++;
            s.insert({-mp[i], i});
            int t = 1;
            for(auto j: s) {
                if(t > K)
                    break;
                row.push_back(j.second);
                t++;
            }
            res.push_back(row);
        }
        return res;
    }}
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.