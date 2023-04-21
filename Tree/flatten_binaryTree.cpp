void flatten(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        //preOrder using Morris Traversal
        if (curr->left)
        {

            Node *pred = curr->left;
            while (pred->right != NULL)
            {
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}