## 01. Sorted insert for circular linked list Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1)

Level : `Easy`

### My Approach

- If the linked list is empty (head is NULL), create a new node with the given data and return it as the new head.

- If the data is less than or equal to the data of the current head, insert the new node at the beginning of the linked list. Update the next pointer of the last node to point to the new head.

- If the data is greater than the data of the current head, iterate through the linked list until you find the correct position to insert the new node. The correct position is where the data of the next node is greater than the new data.

- Insert the new node at the correct position and update the pointers accordingly.

- Return the head of the modified linked list.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n)
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //create new node with data
       Node *newNode = new Node(data);
       Node *temp = head;
       
       //if n=0, return new node
       if (!head){
           newNode -> next = newNode;
           return newNode;
       }
       
       //if newNode = first node!
       else if (data <= head->data){
            newNode -> next = head;
            while (temp -> next != head)
                temp = temp->next;
           
           temp -> next = newNode;
           return newNode;
       }
            
       //if n>=2, check for 2 adjacent nodes & insert accordingly
        else{
            while (temp->next != head && data > temp->next->data){
                temp = temp->next;
            }
            
            newNode -> next = temp->next;
            temp -> next = newNode;
            return head;
        }       
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.