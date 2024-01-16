class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        TreeNode *t1 = root->left, *t2 = root->right;
        root->left = invertTree(t2), root->right = invertTree(t1);

        return root;
    }
};