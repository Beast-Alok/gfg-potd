## 01. Panagram Checking Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1)

Level : `Easy`

### My Approach

- The `checkPangram` function takes a string `s` as input and returns a boolean value (`true` if `s` is a pangram, and `false` otherwise).

- The function first checks if the length of the string is less than 26 (the number of letters in the English alphabet). If the length is less than 26, it immediately returns `false` since a pangram must contain at least 26 distinct letters.

- It initializes an array `arr` of size 26 to store the count of occurrences of each letter in the alphabet. The array is initialized with all elements set to 0.

- It then iterates through each character of the input string `s`. For each character, it checks if it is a lowercase letter ('a' to 'z') or an uppercase letter ('A' to 'Z'). If it is a lowercase letter, it increments the corresponding count in the `arr` array. If it is an uppercase letter, it also increments the corresponding count.

- After processing all characters in the string, it checks the `arr` array to see if there is any letter with a count less than or equal to 0. If there is any such letter, the function returns `false` because it means that the string does not contain all the letters of the alphabet.

If the loop completes without returning `false`, it means that the string is a pangram, and the function returns `true`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O( |s| )
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution
{
  public:
    bool checkPangram (string s) {
        if(s.size()<26)
        return 0;
        
        int arr[26] ={0};
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z')
            arr[s[i]-'a']++;
            
            
            if(s[i]>='A' && s[i]<='Z')
            arr[s[i]-'A']++;
        }
        
        for(int i=0;i<26;i++){
            if(arr[i]<=0){
                return 0;
            }
        }
        return 1;
    }

};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.