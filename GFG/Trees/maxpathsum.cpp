#include <iostream>
#include <climits>
using namespace std;
struct TreeNode{
   int val;
   TreeNode *left,*right;
};
int maxpathsum(TreeNode *root,int &res)
{
   int l,r,max,max_single;
   if(root==NULL)
       return 0;
   else
     {
       max=root->val;
       l=maxpathsum(root->left,res);
       r=maxpathsum(root->right,res);
       max_single=max+(l>r?l:r);
       max_single=max>max_single?max:max_single;
     }
   int max_top=max_single>(l+r+root->val)?max_single:(l+r+root->val);
   res=res>max_top?res:max_top;
   return max_single;
}
TreeNode * newTreeNode(int num)
{
    TreeNode *temp=new TreeNode;
    temp->val=num;
    temp->right=temp->left=NULL;
    return temp;
}
int main()
{
  int num=INT_MIN;
  struct TreeNode *root = newTreeNode(10);
    root->left        = newTreeNode(2);
    root->right       = newTreeNode(10);
    root->left->left  = newTreeNode(20);
    root->left->right = newTreeNode(1);
    root->right->right = newTreeNode(-25);
    root->right->right->left   = newTreeNode(3);
    root->right->right->right  = newTreeNode(4);
   maxpathsum(root,num);
   cout<<num<<"\n";
  return 0;

}
