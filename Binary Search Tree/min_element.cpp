int minValue(Node *root)
{
    if (root == NULL)
        return -1;

    Node *temp = root;

    while (temp->left != nullptr) temp = temp->left;
    
    return temp->data;
}