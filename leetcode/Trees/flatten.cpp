#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
TreeNode* preorder(TreeNode *root)
    {
        TreeNode *newroot=NULL;
        if(root==NULL)
           return NULL;
        newroot=new TreeNode(root->val);
        cout<<"in node : "<<root->val<<"\n";
        if(root->left!=NULL)
        {
      //      cout<<"left child : "<<root->left->val<<"\n";
            newroot->right=preorder(root->left);
        //    cout<<"mod "<<newroot->right->val<<"\n";
        }
        if(root->right!=NULL&&root->left!=NULL)
        {
          //  cout<<"right child : "<<root->right->val<<"\n";
            TreeNode *temp=newroot;
            while(temp->right!=NULL)
                  temp=temp->right;
            temp->right=preorder(root->right);
            cout<<"in node : "<<newroot->val<<"\n";
            cout<<"mod "<<newroot->right->val<<"\n";
            cout<<"mod "<<newroot->right->right->val<<"\n";
        }
        else if(root->right!=NULL)
        {
            newroot->right=preorder(root->right);
            cout<<"mod "<<newroot->right->val<<"\n";
        }
        return newroot;
        
    }
void preorder_print(TreeNode *root)
    {
        if(root!=NULL)
            cout<<root->val<<"\n";
        else
            return;
        if(root->left!=NULL)
        {
            cout<<"in left\n";
            preorder_print(root->left);
        }
        else if(root->right!=NULL)
        {
            cout<<"NULL\n";
        }
        if(root->right!=NULL)
        {
            preorder_print(root->right);
        }
        
        
    }
TreeNode* flatten(TreeNode* root) {
       // if(r)
        TreeNode *newroot=NULL;
        
        newroot=preorder(root);
        return newroot;
        
    }
int main()
{
    TreeNode *root    = new TreeNode(10);
    root->left        = new TreeNode(12);
/*    root->right       = new TreeNode(15);
    root->left->left  = new TreeNode(25);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(36);
    cout<<"Orignal\n";*/
//    preorder_print(root);
    TreeNode *newroot=flatten(root);
    cout<<"New \n";
    preorder_print(newroot);
    return 0;
}