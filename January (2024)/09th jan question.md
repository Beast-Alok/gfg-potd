## 01. Search Pattern (KMP-Algorithm) Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/search-pattern0205/1)

Level : `Medium`

### My Approach
I solved this problem by creating multiple substring of `text` and checking it with `pattern`.
[First i solved this problem in wrong way because of which some test cases exceeds the time. My approach was create substring and check with pattern but here i was creating a subtring and checking even if first letter of subtring is matching or not]
- But now first we will check first letter of `pattern` with first letter of our upcoming substring.
- If it matches so we will create a substring of `text` and check it with our `pattern`.
- If pattern also matches, so we will append the position `i` in vector `pos` and moved to next iteration. 

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(|txt|)
- **Auxiliary Space Complexity** : O(|txt|)

### Code (C++)
```cpp
class Solution {
  public:
    vector <int> search(string pat, string txt)
    {
        vector<int> pos;
        for(int i = 0; i <= txt.length()-pat.length(); i++){
            if(txt[i] == pat[0]){
                string sub = txt.substr(i,pat.length());
                if (sub == pat){
                    pos.push_back(i+1);
                }
            }
        }
        if (pos.size() == 0){
            pos.push_back(-1);
        }
        return pos;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.