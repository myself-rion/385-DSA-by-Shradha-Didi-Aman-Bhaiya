void inOrder(Node *root, vector<int> &inOrderValues) // inOrder of a BST is always in sorted order
{
    if (root == NULL)
        return;

    inOrder(root->left, inOrderValues);
    inOrderValues.push_back(root->data);
    inOrder(root->right, inOrderValues);
}

Node *buildBST(int start, int end, vector<int> &inOrderValues)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(inOrderValues[mid]); // root node
    root->left = buildBST(start, mid - 1, inOrderValues); // left subtree
    root->right = buildBST(mid + 1, end, inOrderValues); // right subtree

    return root;
}

Node *buildBalancedTree(Node *root)
{
    vector<int> inOrderValues; // store inOrder traversal
    inOrder(root, inOrderValues);

    return buildBST(0, inOrderValues.size() - 1, inOrderValues);
}