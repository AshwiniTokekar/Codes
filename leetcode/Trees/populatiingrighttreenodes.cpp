#include <iostream>
using namespace std;
struct TreeLinkNode
{
  int val;
  TreeNode *left,*right,*next;
};
//Level Order Traversal
void connect(TreeLinkNode *root) {
        
        if(root==NULL)
          return;
        TreeLinkNode *temp;
        queue<TreeLinkNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            temp=q.front();
            if(temp->left!=NULL)
            {
              q.push(temp->left);
              q.push(temp->right);
            }
            q.pop();
            temp->next=q.front();
            if(q.front()==NULL&&q.size()>1)
            {
                 q.push(NULL);
                 q.pop();
            }
            else if(q.front()==NULL&&q.size()==1)
                  q.pop();
            
        }
           
}
int main()
{
  //Missing code for insertion in tree
 return 0;
}
