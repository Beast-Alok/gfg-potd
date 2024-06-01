## 01. Remove K Digits Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-k-digits/1)

Level : `Medium`

### My Approach
I solved this problem by using stack

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(|S|)
- **Auxiliary Space Complexity** : O(|S|)

### Code (C++)
```cpp
class Solution {
  public:
    string removeKdigits(string S, int K) {
        pair<int, int> last = {0, K};
        int n = S.size();
        int index = 0;
        while(index < n){
            if(S[index] != '0'){
                if(K)
                    --K;
                else
                    break;   
                ++index;
            }
            else{
                while(index < n and S[index] == '0'){
                    ++index;
                }                
                last = {index, K};
            }
        }

        stack<int> num;
        int start = last.first;
        K = last.second;
        for(int i = start; i < n; i++){
            while(num.size() and num.top() > (S[i] - '0') and K){
                --K;
                num.pop();
            }    
            num.push(S[i] - '0');
        }
        while(num.size() and K--){
            num.pop();
        }

        string ans = "";
        while(num.size()){
            ans += to_string(num.top());
            num.pop();
        }
        reverse(ans.begin(), ans.end());
        
        if(ans == "")
            ans = "0";
        return ans;
    }
};
```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.