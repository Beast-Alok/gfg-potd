## 01. Water the plants Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/water-the-plants--170646/1)

Level : `Medium`

### My Approach
I solved this problem by using greedy approach.
- First we calculate the covrage of sprinklers and store there starting covrage and ending covrage in vector `cov` in form of pair.
- Now we sort vector `cov`.
- Now using greedy approach i am finding minimum number of sprinklers required by iterating over `cov` and updating the covrage as per needed.
- Now at last if any area is uncovered then it return `-1`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(nlog(n))
- **Auxiliary Space Complexity** : O(n)

### Code (C++)
```cpp
class Solution{
public:
    int min_sprinklers(int gallery[], int n) {
        vector<pair<int, int>> cov;

        for (int i = 0; i < n; i++) {
            if (gallery[i] == -1) {
                cov.push_back({1e7, 1e7});
            } else {
                cov.push_back({i - gallery[i], i + gallery[i]});
            }
        }
        sort(cov.begin(), cov.end());
        
        int take = 0, index = 0, ans = 0;
        while(take < n){
            int nax = take - 1;
            while(index < n and cov[index].first <= take){
                nax = max(nax, cov[index++].second);
            }

            if(nax+1 > take){
                take = nax+1;
                ans++;
            }else{
                return -1;
            }
        }
        return ans;
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.