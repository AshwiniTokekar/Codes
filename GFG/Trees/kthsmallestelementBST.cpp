#include <iostream>
#include <climits>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left,*right;
};
//Morris Traversal
//Inorder traversal iteratively without stack
int kthsmallestelement(TreeNode *root,int k)
{
   int count=0;
   int ksmall=INT_MIN;
   TreeNode *curr=root;
   while(curr!=NULL)
   {
     if(curr->left==NULL)
       {
         count++;
         if(count==k)
           {
            ksmall=curr->val;
           }
         curr=curr->right;
       }
     else
       {
          TreeNode *pre=curr->left;
          while(pre->right!=NULL&&pre->right!=curr)
                pre=pre->right;
          if(pre->right==NULL)
            {
                  //linking to inorder successor
                   pre->right=curr;
                   curr=curr->left;
            }
          else
           {
             pre->right=NULL;
             count++; 
             if(count==k)
                 ksmall=curr->val;
             curr=curr->right;
           }
       }
   }
  return ksmall;
}
TreeNode * insert(TreeNode *root,int num)
{
  if(root==NULL)
      {
        root=new TreeNode;
        root->left=root->right=NULL;
        root->val=num;
        return root; 
      }
  if(root->val<num)
    root->left=insert(root->left,num); 
  else if(root->val>num)
    root->right=insert(root->right,num);
  return root;
}
int main()
{
  TreeNode *root=NULL;
  root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  cout<<kthsmallestelement(root,4)<<"\n";
  return 0;
}
