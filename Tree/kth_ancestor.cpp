Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    //found the node in the tree
    if (root->data == node)
    {
        return root;
    }
    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
         // reached the ancestor or not
        if (k <= 0)
        {
            // locking the ancestor
            k = INT_MAX;
            return root;
        }
        else
        {
            return leftAns;
        }
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        // reached the ancestor or not
        if (k <= 0)
        {
            // locking the ancestor
            k = INT_MAX;
            return root;
        }
        else
        {
            return rightAns;
        }
    }

    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node) // ancestor not found or the node to find is root node
        return -1;
    else
        return ans->data;
}