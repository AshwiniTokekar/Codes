//Approach - check four possibilities:
//1. currnode val is largest
//2. l+r is largest
//3. l or r is largest
//4. l+r+currnode is largest

int dfs(TreeNode *root,int max_single,int &res)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int l=0,r=0;
        if(root->left!=NULL)
        {
            l=dfs(root->left,max_single,res);
        }
        if(root->right!=NULL)
        {
            r=dfs(root->right,max_single,res);
        }
        max_single=(l>r?l:r)+root->val;
        max_single=max_single>root->val?max_single:root->val;
        int max_top=max_single>(l+r+root->val)?max_single:(l+r+root->val);
        res=max_top>res?max_top:res;
        return max_single;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
           return 0;
        int res=INT_MIN,s=INT_MIN;
        dfs(root,s,res);
        
        return res;
    }