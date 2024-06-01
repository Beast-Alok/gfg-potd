#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
// gfg solution from here
class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        void solve(Node *head, long long unsigned int &result){
            if(head == NULL){
                return;
            }
            result = (result*2 + head->data) % 1000000007;
            solve(head->next, result);
        }   
        long long unsigned int decimalValue(Node *head)
        {
           long long unsigned int result = 0;
           solve(head, result);
           return result;
        }
};

void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isEmpty(struct Node *head);
int main()
{
    bool l;
    int i, n, T;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        Solution obj;
        cout << obj.decimalValue(head) << endl;
    }
    return 0;
}
/// code written by alok kumar raghuwanshi