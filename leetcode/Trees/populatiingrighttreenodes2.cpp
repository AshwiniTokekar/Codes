#include <iostream>
#include <queue>
using namespace std;
struct TreeLinkNode
{
  int val;
  TreeLinkNode *right,*left,*next;
};
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
            }
            if(temp->right!=NULL)
            {
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
	//Missing code for Treecreation
	return 0;
}
