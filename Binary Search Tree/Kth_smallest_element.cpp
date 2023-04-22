private:
int solve(Node *root, int &i, int k)
{
    // base condition
    if (root == NULL)
        return -1;
    //left subtree
    int left = solve(root->left, i, k);
    if (left != -1) //the node is found
        return left;
    
    //root part in LNR
    i++;
    if (i == k)
    {
        return root->data;
    }

    //right subtree
    return solve(root->right, i, k);
}

public:
// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K)
{
    int i = 0;
    return solve(root, i, K);
}

//T.C : O(n)
//S.C : O(h)
// Note : Can be optimised using Morris Traversal in O(1) space