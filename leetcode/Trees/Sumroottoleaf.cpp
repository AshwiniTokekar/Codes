//Approach:1
//Iterative with two stacks
int totalsum=0;
    int sumNumbers(TreeNode* root) {
        TreeNode *temp;
        int num=0;
        if(root==NULL)
            return 0;
        stack <TreeNode*>curnode;
        stack<int>sum;
        //pair<TreeNode*,int> temp=make_pair(root,num),t;
        curnode.push(root);
        sum.push(num);
        while(!curnode.empty())
        {
            temp=curnode.top();
            num=sum.top();
            sum.pop();
            curnode.pop();
            num=(num*10)+temp->val;
            if(temp->left==NULL&&temp->right==NULL)
            {
                totalsum+=num;
            }
            if(temp->left!=NULL)
            {
                curnode.push(temp->left);
                sum.push(num);
            }
            if(temp->right!=NULL)
            {
                curnode.push(temp->right);
                sum.push(num);
            }
        }
        return totalsum;
    }
//Approach:2
//Recursive
int totalsum=0;
    int sumNumbers(TreeNode* root) {
        int num=0;
        dfs(root,num);
        return totalsum;
    }
    void dfs(TreeNode *root,int num)
    {
        int x;
        if(root!=NULL)
        {
            x=num*10+root->val;
        }
        else
          return;
        //Current node is leaf  
        if(root->left==NULL&&root->right==NULL)  
        {
            totalsum+=x;
        }
        if(root->left!=NULL)
           dfs(root->left,x);
        if(root->right!=NULL)
           dfs(root->right,x);
        
    }    
//Approach:3
//Iterative with one stack using pairs
int totalsum=0;
    int sumNumbers(TreeNode* root) {
        int num=0;
        if(root==NULL)
            return 0;
        stack <pair<TreeNode*,int> >st;
        pair<TreeNode*,int> temp=make_pair(root,num),t;
    //    dfs(root,num);
        st.push(temp);
        while(!st.empty())
        {
            t=st.top();
            st.pop();
            num=(t.second*10)+t.first->val;
            //cout<<t.first->val<<"\n";
            if(t.first->left==NULL&&t.first->right==NULL)
            {
             //   cout<<"in if\n";
                totalsum+=num;
            }
            if(t.first->left!=NULL)
            {
           //     cout<<"in if 2\n";
         //       cout<<t.first->left->val<<"\n";
                temp=make_pair(t.first->left,num);
                st.push(temp);
            }
            if(t.first->right!=NULL)
            {
       //         cout<<"in if 3\n";
     //           cout<<t.first->left->val<<"\n";
                temp=make_pair(t.first->right,num);
                st.push(temp);
            }
        }
        return totalsum;
    }    