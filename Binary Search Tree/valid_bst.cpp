bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data > min && root->data < max)
    {
        bool leftAns = isBST(root->left, min, root->data);
        bool rightAns = isBST(root->right, root->data, max);
        return (leftAns && rightAns);
    }
    return false;
}
// Function to check whether a Binary Tree is BST or not.
bool isBST(Node *root)
{
    // Your code here
    if (root->left == NULL && root->right == NULL)
        return true;
    else
        return isBST(root, INT_MIN, INT_MAX);
}