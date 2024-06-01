class Solution
{
        int inorder(Node * root){
         if(root->left==NULL && root->right==NULL){
             return root->data;
         }
         int left =0 ,right =0 ;
         if(root->left!=NULL)
          left = inorder(root->left);
         if(root->right!=NULL)
          right = inorder(root->right);
         return left + right;
    }
    public:
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
             int ans = inorder(root);
             return ans;
        }
};
