## 01. Find duplicate rows in a binary matrix Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1)

Level : `Medium`

### My Approach
I solved this problem by using set which store vector in it (you can also use other data stuctures for it also).

- Here i use to store whole vector row at once in set `st` but if that vector is already present in the set the i record that position or index and store in another vector `ans`.
- At last return the vector `ans`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(R * C)
- **Auxiliary Space Complexity** : O(R * C)

### Code (C++)
```cpp
class Solution {
  public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        set<vector<int>> st;
        vector<int> ans;
        for(int i = 0; i<M; i++){
            auto val = st.find(matrix[i]);
            if(val != st.end()){
                ans.push_back(i);
            }else{
                st.insert(matrix[i]);
            }
        }
        return ans;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.