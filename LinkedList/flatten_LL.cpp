Node *mergeTwoLists(Node *l1, Node *l2) //merge 2 sorted list function
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->data <= l2->data)
    {
        l1->bottom = mergeTwoLists(l1->bottom, l2);
        return l1;
    }
    else
    {
        l2->bottom = mergeTwoLists(l2->bottom, l1);
        return l2;
    }
}

Node *flatten(Node *root)
{
    if (root->next == NULL)
        return root;

    root->next = flatten(root->next);

    root = mergeTwoLists(root, root->next);

    return root;
}