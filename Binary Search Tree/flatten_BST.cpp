void inOrder(TreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> v;

    inOrder(root, v);

    TreeNode<int> *newRoot = new TreeNode<int>(v[0]);
    TreeNode<int> *curr = newRoot;
    for (int i = 1; i < v.size(); i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(v[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    //standing on the last element
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}