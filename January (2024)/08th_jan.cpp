#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// GFG solution from here
class Solution
{
    public:
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node* node3 = NULL, *temp3 = NULL;
        while(node1 != NULL || node2 != NULL){
            if (node1 != NULL && node2 == NULL)
            {
                if(node3 == NULL){
                    node3 = temp3 = newNode(node1->data);
                    node1 = node1->next;
                }else{
                    temp3 = newNode(node1->data);
                    node1 = node1->next;
                    temp3->next = node3;
                    node3 = temp3;
                }
            }
            else if (node2 != NULL && node1 == NULL)
            {
                if(node3 == NULL){
                    node3 = temp3 = newNode(node2->data);
                    node2 = node2->next;
                }else{
                    temp3 = newNode(node2->data);
                    node2 = node2->next;
                    temp3->next = node3;
                    node3 = temp3;
                }
            }
            else if(node1->data <= node2->data){
                if(node3 == NULL){
                    node3 = temp3 = newNode(node1->data);
                    node1 = node1->next;
                }else{
                    temp3 = newNode(node1->data);
                    node1 = node1->next;
                    temp3->next = node3;
                    node3 = temp3;
                }
            }
            else if (node1->data > node2->data){
                if(node3 == NULL){
                    node3 = temp3 = newNode(node2->data);
                    node2 = node2->next;
                }else{
                    temp3 = newNode(node2->data);
                    node2 = node2->next;
                    temp3->next = node3;
                    node3 = temp3;
                }
            }
        }
        return node3;
    }  
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// code written by alok kumar raghuwanshi