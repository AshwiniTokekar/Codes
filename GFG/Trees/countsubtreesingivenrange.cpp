#include <iostream>
using namespace std;
struct TreeNode
{
   int val;
   TreeNode *left,*right;
};
int nosinrange(TreeNode *root,int min,int max)
{
  if(root==NULL)
      return 0;  
  int l=nosinrange(root->left,min,max);
  int r=nosinrange(root->right,min,max);
  if(root->val>=min&&root->val<=max)
     {
         return l+r+1;
     }
  else if(l!=0||r!=0)
      return l+r;
  else 
     return 0;
}
TreeNode* newNode(int num)
{
  TreeNode *temp=new TreeNode;
  temp->val=num;
  temp->left=temp->right=NULL;
  return temp;
}
int main()
{
  TreeNode *root=newNode(10);
  root->left        = newNode(5);
    root->right       = newNode(50);
    root->left->left  = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
   cout<<nosinrange(root,15,45)<<"\n";
  return 0;
}
