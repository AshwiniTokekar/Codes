#include <iostream>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
 };
struct TreeNode* insert(TreeNode *root,int num)
{
   if(root==NULL)
     {
        root=new TreeNode;
        root->right=root->left=NULL;
        root->val=num; 
     } 
  else if(root->val>num)
       root->left=insert(root->left,num);
  else 
       root->right=insert(root->right,num);
   return root;
}

void intersection(TreeNode *root1,TreeNode *root2)
{
     stack<TreeNode*>st1,st2;
     //TreeNode *temp=root1;
     while(1)
      {
           if(root1)
             {
                 st1.push(root1);
                 root1=root1->left;
             }
          else if(root2)
             {
                 st2.push(root2);
                 root2=root2->left;
             }
         else if(!st1.empty() && !st2.empty())
             {
                  root1=st1.top();
                  root2=st2.top();
//                  cout<<root1->val<<" "<<root2->val<<"\n";
                  if(root1->val==root2->val)
                   {
                      cout<<root1->val<<"\n";
                      st1.pop();
                      st2.pop();
                      root1=root1->right;
                      root2=root2->right;
                   }
                else if(root1->val<root2->val)
                   {
                         st1.pop();
                         root1=root1->right;
                         root2=NULL;
                   }
               else if(root1->val > root2->val)
                  {
                       st2.pop();
                       root2=root2->right;
                       root1=NULL;
                  }
                  
              }
          else
              break;
      }
}
void inordertraversal(TreeNode* root)
  {
    if(root==NULL)
         return;
    inordertraversal(root->left);
    cout<<root->val<<" ";
    inordertraversal(root->right);
  }
int main()
{

 TreeNode *root1 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1,  0);
    root1 = insert(root1,  4);
    root1 = insert(root1,  7);
    root1 = insert(root1,  9);
 
    // Create second tree as shown in example
    TreeNode *root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);
    inordertraversal(root1);
    cout<<"\n";
    inordertraversal(root2);
    cout<<"\n";
    cout<<"Common nodes\n";
    intersection(root1,root2);
//    cout<<"\n";
  return 0;
}
