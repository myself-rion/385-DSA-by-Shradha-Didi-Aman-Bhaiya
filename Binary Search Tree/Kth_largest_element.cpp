class Solution
{
    int ans = 0, node = 0;
    void findInOrder(Node *root, int K)
    {
        if (!root)
            return;

        findInOrder(root->right, K);

        node += 1;

        if (K == node)
        {
            ans = root->data;
            return;
        }

        findInOrder(root->left, K);
    }

public:
    int kthLargest(Node *root, int K)
    {
        findInOrder(root, K);
        return ans;
    }
};