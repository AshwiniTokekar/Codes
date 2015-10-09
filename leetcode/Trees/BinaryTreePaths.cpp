//Approach:1
//Using DFS stack
vector<string>ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
           return ans;
        string temp;//=to_string(root->val);
        dfs(root,temp);
        return ans;
    }
    void dfs(TreeNode *root,string temp)
    {
        
        temp.append(to_string(root->val));
        if(root->left==NULL&&root->right==NULL)
        {
            ans.push_back(temp);
        }
        if(root->left!=NULL)
        {
            temp.append("->");
            dfs(root->left,temp);
        }
        if(root->right!=NULL)
        {
            if(root->left==NULL)
               temp.append("->");
            dfs(root->right,temp);
        }
    }