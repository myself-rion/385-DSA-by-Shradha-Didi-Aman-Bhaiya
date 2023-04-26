TreeNode *getBST(vector<int> &preorder, int &i, int maxi)
{
    if (i >= preorder.size() || preorder[i] > maxi) // maxi = upper bound
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = getBST(preorder, i, root->val);
    root->right = getBST(preorder, i, maxi);

    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0; // iterating through vector

    return getBST(preorder, i, INT_MAX);
}