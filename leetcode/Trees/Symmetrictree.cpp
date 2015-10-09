bool isSym(TreeNode *r1,TreeNode *r2)
    {
        bool iseq=false;
        if(r1==NULL&&r2==NULL)
            return true;
        if(r1==NULL||r2==NULL)
            return false;
        if(r1->val==r2->val) 
           iseq=true;
        if(iseq)
        {
        bool one=isSym(r1->left,r2->right);
        bool two=isSym(r1->right,r2->left);
        return one&&two;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        else return isSym(root->left,root->right);
    }