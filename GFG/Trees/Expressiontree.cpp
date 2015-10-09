#include<iostream>
#include <stack>
#include <cstring>
using namespace std;
struct TreeNode{
    string val;
    TreeNode *left,*right;
};

int evaluation(TreeNode *root)
{
   if(root==NULL)
      return 0;
   if(root->val=="+")
   {

       int l=evaluation(root->left); 
       int r=evaluation(root->right);
       return l+r;      
   }
   else if(root->val=="-")
   {

       int l=evaluation(root->left); 
       int r=evaluation(root->right);
        return l-r; 
   }
   else if(root->val=="*")
   {

       int l=evaluation(root->left); 
       int r=evaluation(root->right);
        return l*r; 
   }
   else if(root->val=="/")
   {

       int l=evaluation(root->left); 
       int r=evaluation(root->right);
        return l/r; 
   }
   
  else
     return stoi(root->val);
}
int main()
{
   TreeNode *root=NULL;
   stack<TreeNode*> st;
   int noe;
   string ele;
   cin>>noe;
   while(noe)
   {
     noe--;
     cin>>ele;
//     cout<<ele<<"\n";
     if(ele=="+"||ele=="-"||ele=="*"||ele=="/")
        {
           TreeNode *temp=new TreeNode;
                temp->val=ele;
                temp->left=st.top();
                st.pop();
                temp->right=st.top();  
                st.pop();
                st.push(temp);
        }
     else
        {
         
           TreeNode *temp=new TreeNode;
           temp->val=ele;
           temp->left=temp->right=NULL;
           st.push(temp);
        }

  }
  root=st.top();
  cout<<evaluation(root)<<"\n";  
  return 0;
}
