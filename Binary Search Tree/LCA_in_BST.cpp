Node *LCA(Node *root, int n1, int n2)
{
    Node *temp = root;

    while (temp)
    {
        // Ancestor lies in right subtree
        if (temp->data < n1 && temp->data < n2)
        {

            temp = temp->right;
        }

        // Ancestor lies in left subtree
        else if (temp->data > n1 && temp->data > n2)
        {

            temp = temp->left;
        }

        //found ancestor
        else
        {
            return temp;
        }
    }
}