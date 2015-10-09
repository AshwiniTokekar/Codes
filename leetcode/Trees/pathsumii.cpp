//Approach:1
//Pre-processing global variable declaration
//Runtime:12ms
vector<vector<int> >ans;
vector<int>sol;
vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if(root==NULL)
           return ans;
        int tempsum=0;
        //vector<int>v;
        preorder(root,sum);
        return ans;
    }
    void preorder(TreeNode *root,int sum)
    {
        sum-=root->val;
        sol.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&sum==0)
        {
           
                  ans.push_back(sol);
              
        }
        if(root->right!=NULL)
        {
            preorder(root->right,sum);
            sol.pop_back();
        }
        if(root->left!=NULL)
        {
            preorder(root->left,sum);
            sol.pop_back();
        }
}

//Approach:2
//No pre-processing
//Runtime:24 ms
vector<vector<int> >ans; 
vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if(root==NULL)
           return ans;
        int tempsum=0;
        vector<int>v;
        preorder(root,tempsum,sum,v);
        return ans;
    }
    void preorder(TreeNode *root,int tempsum,int sum,vector<int>v)
    {
        tempsum+=root->val;
        v.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            if(tempsum==sum)
              {
                  ans.push_back(v);
              }
        }
        if(root->right!=NULL)
        {
            preorder(root->right,tempsum,sum,v);
        }
        if(root->left!=NULL)
        {
            preorder(root->left,tempsum,sum,v);
        }
    }