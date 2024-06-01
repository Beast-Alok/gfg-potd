## 01. Insert and Search in a Trie Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1)

Level : `Medium`

### My Approach

**insert Method:**

- This method is used to insert a word into the Trie.
- It takes two parameters: a TrieNode pointer `root` (representing the `root` of the Trie) and a string `key` (the word to be inserted).
- The method iterates over each character in the input word.
- For each character:
    - It checks if the corresponding child node for the character exists. If not, it creates a new node.
    - It moves the `root` pointer to the child node corresponding to the current character.
- After processing all characters, it marks the last node as a leaf node, indicating that a complete word has been inserted.

**search Method:**

- This method is used to search for a word in the Trie.
- It takes two parameters: a TrieNode pointer `root` (representing the `root` of the Trie) and a string `key` (the word to be searched).
- The method iterates over each character in the input word.
- For each character:
    - It checks if the corresponding child node for the character exists. If not, it returns `false` since the word is not present in the Trie.
    - It moves the `root` pointer to the child node corresponding to the current character.
- After processing all characters, it checks if the last node is marked as a leaf node. If `true`, it returns `true`, indicating that the word is present in the Trie; otherwise, it returns `false`.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(M+|key|)
- **Auxiliary Space Complexity** : O(M)

### Code (C++)
```cpp
class Solution
{
    public:
        void insert(struct TrieNode *root, string key)
        {
            for (int i=0;i<key.size();i++)
            {
                if (root->children[key[i]-'a']==NULL)
                {root->children[key[i]-'a']=new TrieNode();}
                root=root->children[key[i]-'a'];
            }
            root->isLeaf=true;
        }

        bool search(struct TrieNode *root, string key) 
        {

            for (int i=0;i<key.size();i++)
            {
                if (root->children[key[i]-'a']==NULL) return false;
                root=root->children[key[i]-'a'];
            }
            if (root->isLeaf==true) return true;
            return false;
        }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.