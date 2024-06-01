#include<bits/stdc++.h>
using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
// gfg solution from here
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

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);
    
    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }
    
    if(n>0)
    temp->next=start;
 
    scanf("%d",&x);
    Solution ob;
    start = ob.sortedInsert(start,x);
    printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
  return 0;
}

// code written by alok kumar raghuwanshi