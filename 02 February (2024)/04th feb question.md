## 01. Subtraction in Linked List Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1)

Level : `Hard`

### My Approach

**Private Member Variables**:

- ``borrow``: A variable to keep track of the borrow during subtraction. It is initialized to 0.

**Private Helper Functions**:

- ``reverse``: Reverses a linked list and returns the new head.
- ``len``: Calculates the length of a linked list.
- ``sub``: Performs subtraction of two linked lists.
- ``gen_ans``: Generates the answer by reversing the linked list and removing leading zeros.

**Public Member Function**:

- ``subLinkedList``: The main function that takes two linked lists (head1 and head2) representing numbers and returns the linked list representing their subtraction. It handles leading zeros, determines the lengths of the linked lists, and calls the private helper functions (reverse, len, sub, gen_ans) to perform the subtraction.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n+m)
- **Auxiliary Space Complexity** : O(n+m)

### Code (C++)
```cpp
class Solution {
private:
    int borrow = 0;  // Variable to keep track of borrow during subtraction

    // Function to reverse a linked list and return the new head
    Node* reverse(Node* head) {
        Node* curr = head, *tmp, *prev = NULL; 
        while (curr) 
            tmp = curr->next, curr->next = prev, prev = curr, curr = tmp; 
        return prev;
    }
    
    // Function to calculate the length of a linked list
    int len(Node *head) {
        int l = 0;
        Node* tmp = head;
        while(tmp) 
            tmp = tmp->next, l++;
        return l;
    }

    // Function to perform subtraction of two linked lists
    Node* sub(Node* a, Node* b) {
        if (a == NULL && b == NULL) return NULL;
        if (b == NULL) {
            int diff = a->data - borrow;
            if (diff < 0) 
                diff += 10, borrow = 1;
            else 
                borrow = 0;
            Node* nn = new Node(diff);
            nn->next = sub(a->next, b);
            return nn;
        }
        int diff = a->data - b->data - borrow;
        if (diff < 0) 
            diff += 10, borrow = 1;
        else 
            borrow = 0;
        Node* nn = new Node(diff);
        nn->next = sub(a->next, b->next);
        return nn;
    }

    // Function to generate the answer by reversing the linked list and removing leading zeros
    Node* gen_ans(Node* head) {
        head = reverse(head);
        while (head && head->data == 0) 
            head = head->next;
        return head;
    }

public:
    // Main function to subtract two linked lists representing numbers
    Node* subLinkedList(Node* head1, Node* head2) {
        // Remove leading zeros
        while (head1 && head1->data == 0) 
            head1 = head1->next;
        while (head2 && head2->data == 0) 
            head2 = head2->next;
        
        // Handle cases where one or both linked lists are empty
        if (head1 == NULL && head2 == NULL) 
            return new Node(0);
        else if (head1 == NULL) 
            return head2;
        else if (head2 == NULL) 
            return head1;
        
        // Calculate the lengths of the linked lists
        int l1 = len(head1), l2 = len(head2); 

        // Perform subtraction based on the lengths of the linked lists
        if (l1 < l2) 
            return gen_ans(sub(reverse(head2), reverse(head1)));
        else if (l1 > l2) 
            return gen_ans(sub(reverse(head1), reverse(head2)));
        
        // Handle cases where lengths are equal, compare individual digits
        Node* t1 = head1, *t2 = head2;
        while (t1 && t2 && t1->data == t2->data) 
            t1 = t1->next, t2 = t2->next;

        // Check the remaining digits and perform subtraction accordingly
        if (t1 == NULL) 
            return new Node(0);
        if (t1->data < t2->data) 
            return gen_ans(sub(reverse(head2), reverse(head1)));
        return gen_ans(sub(reverse(head1), reverse(head2)));
    }
};

```

### Contribution and Support

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [Beast-ALok/gfg-potd](https://github.com/Beast-ALok/gfg-potd) repository.